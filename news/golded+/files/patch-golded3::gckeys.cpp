--- ./golded3/gckeys.cpp.orig	Mon Oct 20 02:43:53 2003
+++ ./golded3/gckeys.cpp	Mon Oct 20 02:49:54 2003
@@ -825,9 +825,9 @@
 
 //  ------------------------------------------------------------------
 
-void RunMacro(Macro* m) {
+void RunMacro(const Macro& m) {
 
-  gkey* mac = m->buf;
+  const gkey* mac = m.buf;
   while(*mac) {
     kbput(*mac);
     mac++;
@@ -839,7 +839,7 @@
 
 static void PlayMacro() {
 
-  RunMacro(&CFG->macro[0xFFFF-gkbd.curronkey->pass]);
+  RunMacro(CFG->macro[0xFFFF-gkbd.curronkey->pass]);
 }
 
 
