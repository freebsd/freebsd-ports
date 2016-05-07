--- compat/compat.h.orig	2015-11-01 10:44:25 UTC
+++ compat/compat.h
@@ -42,17 +42,6 @@
 #endif
 #endif
 
-/* Solaris 10 has a broken definition for minor_t in IPFilter compat.
- * We must pre-define before doing anything with OS headers so the OS
- * do not. Then un-define it before using the IPFilter *_compat.h headers.
- */
-#if IPF_TRANSPARENT && USE_SOLARIS_IPFILTER_MINOR_T_HACK
-/* But we only need do this nasty thing for src/ip/Intercept.cc */
-#if BUILDING_SQUID_IP_INTERCEPT_CC
-#define minor_t solaris_minor_t_fubar
-#endif
-#endif
-
 /*****************************************************/
 /* FDSETSIZE is messy and needs to be done before    */
 /* sys/types.h are defined.                          */
