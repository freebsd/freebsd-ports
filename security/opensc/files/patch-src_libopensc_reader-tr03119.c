--- src/libopensc/reader-tr03119.c.orig	2017-10-26 14:16:19 UTC
+++ src/libopensc/reader-tr03119.c
@@ -40,7 +40,7 @@
 #ifndef _BSD_SOURCE
 #define _BSD_SOURCE             /* See feature_test_macros(7) */
 #endif
-#include <endian.h>
+#include <sys/endian.h>
 #endif
 
 static const u8 escape_cla                          = 0xff;
