--- multiping.c.orig	Mon Sep  1 06:40:12 2003
+++ multiping.c	Mon Sep  8 00:19:31 2003
@@ -21,6 +21,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <signal.h>
 #include <gkrellm2/gkrellm.h>
 #include <sys/types.h>
 #include <sys/wait.h>
@@ -30,7 +31,7 @@
 #define	CONFIG_NAME	"Multiping"
 #define	STYLE_NAME	"multiping"
 
-#define COMMAND "/usr/local/lib/gkrellm2/plugins/pinger"
+#define COMMAND "@COMMAND@"
 
 static GkrellmMonitor *monitor;
 static GkrellmPanel *panel;
