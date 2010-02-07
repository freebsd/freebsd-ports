--- js/src/jsnum.cpp.orig	2009-10-14 18:03:30.000000000 +0200
+++ js/src/jsnum.cpp	2009-10-15 21:49:44.000000000 +0200
@@ -43,6 +43,9 @@
 /*
  * JS number type and wrapper class.
  */
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 #ifdef XP_OS2
 #define _PC_53  PC_53
 #define _MCW_EM MCW_EM
@@ -691,8 +694,16 @@
 
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
