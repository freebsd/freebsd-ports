--- qst.c.orig	Thu Aug  9 15:43:44 2001
+++ qst.c	Thu Aug  9 15:45:58 2001
@@ -36,7 +36,7 @@
 #define QSTATCMD "qstat"
 #define GAMETYPE "-q3s"
 #define GAMEBIN  "quake3"
-#define SERVERLOC "quake" /* server:port */
+#define SERVERLOC "server:port" /* less confuse people */
 #define AWK      "awk"
 #define XTERM    "xterm"
 #define StatusChgCmd "echo \"We've got Quake!\""
