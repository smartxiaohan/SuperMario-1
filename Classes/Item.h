#ifndef _ITEM_H_
#define _ITEM_H_

#include "cocos2d.h"
#include "GameEnum.h"
using namespace cocos2d;

class CCItem : public CCNode
{
public:
	CCItem(ItemType _itemtype);
	~CCItem();
	CCSprite *itemBody;   // ��Ҫ��block���item��Ӧ�ľ���
	ItemType itemType;    // Item������

	static CCItem* create(ItemType _itemtype);

private:
	bool itemInit();
};

// С���⣬���ƶ��ģ��ɹ�����վ���ģ��ḻ��Ϸ�Ե�С����
class CCGadget : public CCNode
{
public:
	CCGadget();
	virtual ~CCGadget();

	// �������������ϵĸ��£��������˶���
	virtual void gadgetUpdateH();
	virtual void gadgetUpdateV();

	// ���麯��
	virtual void launchGadget() = 0;

	float getMoveOffset();
	float getJumpOffset();

	void setStartPos(CCPoint pos);
	CCPoint getStartPos();

	void setStartFace(int face);

	// ��ȡ��ǰ����ľ��Σ�Ϊ�˼�������Ƿ��ڴ������
	CCRect getGadgetRect();

	// 
	CCSize getGadgetSize();

	GadgetState getGadgetState();

	// ���״̬
	virtual void checkGadgetState();

protected:
	CCSprite *gadgetBody;
	CCSize bodySize;
	GadgetType gadgetType;  //С���������
	GadgetState gadgetState;  // С�����״̬

	float moveOffset;
	float ccMoveOffset;

	float jumpOffset;
	float ccJumpOffset;

	CCPoint startPos;  // ���λ��

	// ��һ���ƶ��ķ�����0��1ѡ��
	// ��LR��0������1������
	// ��UD��0�����ϣ�1������
	int startFace;

};

// �����ƶ�������
class CCGadgetLadderLR : public CCGadget
{
public:
	CCGadgetLadderLR(float dis);
	~CCGadgetLadderLR();

	void gadgetUpdateH();

	void launchGadget();

	void setLRdis(float dis);

	void update(float dt);

private:
	float leftSide;    // ��߽�
	float rightSide;   // �ұ߽�
	float lrDis;       // ���Ҿ���
};

class CCGadgetLadderUD : public CCGadget
{
public:
	CCGadgetLadderUD(float dis);
	~CCGadgetLadderUD();

	void gadgetUpdateV();

	void launchGadget();

	void setUDdis(float dis);

	void update(float dt);

private:
	float upSide;      // �ϱ߽�
	float downSide;    // �±߽�
	float udDis;       // ���¾���
};

#endif