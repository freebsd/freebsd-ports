--- plugger-controller.c.old	Wed Feb 11 16:22:04 2004
+++ plugger-controller.c	Wed Feb 11 16:23:47 2004
@@ -136,7 +136,7 @@
   if(!pid)
   {
     char *cmd[4];
-    setpgrp();
+    setpgrp(0, 0);
     cmd[0]="/bin/sh";
     cmd[1]="-c";
     cmd[2]=argv[1];
