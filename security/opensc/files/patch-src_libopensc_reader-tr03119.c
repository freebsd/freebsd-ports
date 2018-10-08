--- src/libopensc/reader-tr03119.c.orig	2018-09-13 11:52:42 UTC
+++ src/libopensc/reader-tr03119.c
@@ -40,7 +40,7 @@
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE             /* See feature_test_macros(7) */
 #endif
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 int get_pace_capabilities(u8 *bitmap)
