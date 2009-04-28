--- js/src/jsnum.cpp.orig	2009-04-28 11:19:57.888134991 +0000
+++ js/src/jsnum.cpp	2009-04-28 11:21:35.786147448 +0000
@@ -45,6 +45,9 @@
 #if defined(XP_WIN) || defined(XP_OS2)
 #include <float.h>
 #endif
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 #ifdef XP_OS2
 #define _PC_53  PC_53
 #define _MCW_EM MCW_EM
@@ -659,8 +662,16 @@
 
 #else
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 601000
+#include <fenv.h>
+#define FIX_FPU() (fedisableexcept(FE_ALL_EXCEPT))
+
+#else
+
 #define FIX_FPU() ((void)0)
 
+#endif /* defined(__FreeBSD__) && __FreeBSD_version >= 503000 */
+
 #endif
 
 JSBool
