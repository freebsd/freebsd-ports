--- lib/Cm/BtObject.cc.orig	2001-10-11 20:56:13.000000000 -0800
+++ lib/Cm/BtObject.cc	2008-02-03 13:27:51.000000000 -0900
@@ -47,6 +47,6 @@
 BtObject::BtObject(const BtObject&) {}
 BtObject::~BtObject() {}
 uint32_t BtObject::hash() const {return 0;}
-int BtObject::compare(const BtObject*p) const {return (int)this-(int)p;}
+int BtObject::compare(const BtObject*p) const {return (long)this-(long)p;}
 bool BtObject::isEqual(const BtObject* v) const {
 	return compare(v)==0;}
