--- src/std/_c_string.c	2013-02-20 20:39:16.000000000 +0400
+++ src/std/c_string.c	2013-03-16 14:19:04.313916478 +0400
@@ -83,7 +83,7 @@
 
 static char *c_iconv(const char* str, enum iconv_direction dir)
 {
-  char *in = (char*)str;
+  const char *in = (char*)str;
   size_t size;
   size_t outsize;
   char *out;
