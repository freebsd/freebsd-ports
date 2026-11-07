--- source/ni_rsrc_mon.c.orig	2026-10-17 00:01:03 UTC
+++ source/ni_rsrc_mon.c
@@ -26,7 +26,7 @@
  *          registered NETINT video processing devices on system
  ******************************************************************************/
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #include <unistd.h>
 #include <signal.h>
 #include <syslog.h>
