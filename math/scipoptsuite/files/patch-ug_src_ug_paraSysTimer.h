--- ug/src/ug/paraSysTimer.h.orig	2024-06-17 04:20:33 UTC
+++ ug/src/ug/paraSysTimer.h
@@ -55,6 +55,10 @@
 #define BSD
 #endif /* SUN_OS */
 
+#ifdef __FreeBSD__
+#define BSD
+#endif /* SUN_OS */
+
 #ifdef SOLARIS
 #define SYSV
 #endif /* SOLARIS */
