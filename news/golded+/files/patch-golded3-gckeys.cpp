--- golded3/gckeys.cpp.orig	2013-11-18 18:54:22.000000000 +0700
+++ golded3/gckeys.cpp	2013-11-18 18:54:34.000000000 +0700
@@ -989,7 +989,7 @@
 //  ------------------------------------------------------------------
 
 //bool CmdKeyCmp(CmdKey a, CmdKey b) {
-bool operator<(CmdKey &a, CmdKey &b) {
+bool operator<(const CmdKey &a, const CmdKey &b) {
 
   int cmp = CmpV(a.type, b.type);
   if(cmp != 0)
