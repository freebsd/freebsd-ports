--- lib/x86_64/libm_amd.h.orig	2018-09-03 06:03:48 UTC
+++ lib/x86_64/libm_amd.h
@@ -68,7 +68,7 @@ regulations applicable in licensee's jurisdiction.
 
 #include <math.h>
 
-#if !defined(TARGET_WIN)
+#if !defined(TARGET_LINUX)
 typedef long __INT8_T;
 typedef unsigned long __UINT8_T;
 
@@ -79,6 +79,11 @@ typedef unsigned long long __UINT8_T;
 
 /* Open Tools #defines ldexpf */
 #undef ldexpf
+
+#define DOMAIN		1
+#define SING		2
+#define OVERFLOW	3
+#define UNDERFLOW	4
 
 #endif
 
