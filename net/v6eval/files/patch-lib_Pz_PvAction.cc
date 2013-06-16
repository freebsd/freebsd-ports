--- lib/Pz/PvAction.cc.orig	2013-06-16 10:39:01.000000000 +0900
+++ lib/Pz/PvAction.cc	2013-06-16 10:39:29.000000000 +0900
@@ -55,7 +55,7 @@
 PvAction::~PvAction() {}
 void PvAction::print() const {
 	CSTR s=meta()->string();
-	printf(s);}
+	printf("%s", s);}
 
 //======================================================================
 PvAUTO::PvAUTO(const MObject* m,CSTR f,int l):PvAction(m,f,l){}
