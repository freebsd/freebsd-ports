--- ./golded3/geprot.h.orig	Mon Oct 20 02:44:44 2003
+++ ./golded3/geprot.h	Mon Oct 20 02:44:53 2003
@@ -61,7 +61,7 @@
 
 int ReadKeysCfg(int force);
 void KeyCmdAdd(gkey cmd, gkey val, int type);
-void RunMacro(Macro* m);
+void RunMacro(const Macro& m);
 
 
 //  ------------------------------------------------------------------
