--- include/lqt_fseek.h.orig	Thu Jan 23 03:04:20 2003
+++ include/lqt_fseek.h	Wed Nov 12 23:27:17 2003
@@ -16,6 +16,11 @@
 #define ftello64(a) lqt_ftello64(a)
 #endif
 
+#ifdef __FreeBSD__
+#define FTELL ftello
+#define FSEEK fseeko
+#else
 #define FTELL ftello64
 #define FSEEK fseeko64
+#endif
 
