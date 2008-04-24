--- ./AP_commons.h.orig	2006-08-27 02:35:15.000000000 +0000
+++ ./AP_commons.h	2008-04-21 16:40:55.000000000 +0000
@@ -38,15 +38,6 @@
 #endif
 #endif /*_UINT32_T */
 
-#ifndef _UINT64_T
-#define _UINT64_T
-#if defined (_MSC_VER)
-typedef unsigned __int64	 uint64_t;
-#else
-typedef unsigned long long   uint64_t;
-#endif /* _MSC_VER */
-#endif /* _UINT64_T */
-
 #ifndef _INT16_T
 #define _INT16_T
 typedef short       int16_t;
