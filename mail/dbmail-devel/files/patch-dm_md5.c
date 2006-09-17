--- dm_md5.c.orig	Sat Sep 16 20:42:05 2006
+++ dm_md5.c	Sat Sep 16 20:44:42 2006
@@ -42,6 +42,8 @@
 
 #include "dbmail.h"
 
+typedef unsigned int uint32;
+
 /* If endian.h is present, it will tell us, otherwise
  * autoconf's AC_C_BIGENDIAN will have tested the host. */
 #if (BYTE_ORDER == LITTLE_ENDIAN) || !defined(WORDS_BIGENDIAN)
@@ -63,8 +65,6 @@
 }
 
 #endif
-
-typedef unsigned int uint32;
 
 struct GdmMD5Context {
 	uint32 buf[4];
