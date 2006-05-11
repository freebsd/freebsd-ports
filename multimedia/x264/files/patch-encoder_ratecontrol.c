--- encoder/ratecontrol.c.orig  Thu May 11 13:35:36 2006
+++ encoder/ratecontrol.c       Thu May 11 13:36:57 2006
@@ -38,6 +38,9 @@
 #if defined(SYS_FREEBSD) || defined(SYS_BEOS) || defined(SYS_NETBSD)
 #define exp2f(x) powf( 2, (x) )
 #endif
+#if defined(__FreeBSD__) && (__FreeBSD__ < 5)
+#define isfinite(val) (!isnan((val)) && !isinf((val)))
+#endif
 #if defined(SYS_MACOSX)
 #define exp2f(x) (float)pow( 2, (x) )
 #define sqrtf sqrt

