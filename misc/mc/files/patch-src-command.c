--- src/command.c.orig	Thu Nov 14 13:25:19 2002
+++ src/command.c	Tue Jun 15 03:15:09 2004
@@ -258,7 +258,7 @@
 WInput *
 command_new (int y, int x, int cols)
 {
-    WInput *cmd = g_new (WInput, 1);
+    WInput *cmd;
 
     cmd = input_new (y, x, DEFAULT_COLOR, cols, "", "cmdline");
 
