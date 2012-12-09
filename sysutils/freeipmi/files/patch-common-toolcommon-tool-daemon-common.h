--- common/toolcommon/tool-daemon-common.h.orig	2012-06-01 05:33:32.000000000 +0800
+++ common/toolcommon/tool-daemon-common.h	2012-10-10 21:47:30.807406009 +0800
@@ -22,6 +22,8 @@
 #include <stdint.h>
 #include <signal.h>
 
+typedef void (*sighandler_t)(int);
+
 int daemonize_common (const char *pidfile);
 
 /* can pass NULL for no callback */
