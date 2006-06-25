--- kaspaliste/klib/kaspabase.cpp.orig	Sat Feb  7 10:54:32 2004
+++ kaspaliste/klib/kaspabase.cpp	Sun Mar 19 12:34:42 2006
@@ -184,7 +184,19 @@
 LockTableItem *KaspaBase::locktable=0L;
 
 Oid KaspaBase::getNo(Str tab, Oid o) {
-  exec("select no from "+tab+" where oid="+oid2str(o));
+  char* cdummy1 = "select no from ";
+  char* cdummy2 = " where oid=";
+
+  Str sdummy1, sdummy2, sdummy_all;
+  sdummy1 = cdummy1;
+  sdummy2 = cdummy2;
+  sdummy_all = sdummy1;
+  sdummy_all += tab;
+  sdummy_all += sdummy2;
+  sdummy_all += oid2str(o);
+
+  const char* cdummy_all = sdummy_all.data();
+  exec(cdummy_all);
   if(tuples())
     return str2oid(getValue(0, "no"));
   else
