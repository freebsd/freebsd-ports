--- src/mn-md5.c.orig	Fri Aug 20 19:35:18 2004
+++ src/mn-md5.c	Fri Aug 20 19:35:26 2004
@@ -42,7 +42,7 @@
  * is a multiple of 4.
  */
 static void
-mn_md5_encode (unsigned char *output, u_int32_t input, unsigned int len)
+mn_md5_encode (unsigned char *output, u_int32_t *input, unsigned int len)
 {
   unsigned int i, j;
 
