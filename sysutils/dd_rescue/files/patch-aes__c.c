--- aes_c.c.orig	2022-07-30 04:37:00 UTC
+++ aes_c.c
@@ -32,8 +32,6 @@
 
 #include <string.h>
 #include <assert.h>
-#include <byteswap.h>
-#include <endian.h>
 
 typedef unsigned char u8;
 typedef unsigned short u16;
