--- vde.h	Sat Jan 29 15:02:08 2005
+++ vde.h	Sun Jan 30 11:39:43 2005
@@ -2,6 +2,12 @@
 #define VDESTDSOCK	"/tmp/vde.ctl"
 #endif
 
+#ifdef __FreeBSD__
+#ifndef VDEDATSOCK
+#define VDEDATSOCK	"/tmp/.vde.data"
+#endif
+#endif
+
 #define DO_SYSLOG
 #define VDE_IP_LOG
 
