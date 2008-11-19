--- ./base64.c.orig	2002-05-07 09:26:43.000000000 -0400
+++ ./base64.c	2008-11-17 18:55:03.000000000 -0500
@@ -31,7 +31,7 @@
 };
 #define DECODE64(c)  (isascii(c) ? base64val[c] : BAD)
 
-void to64frombits(unsigned char *out, const unsigned char *in, int inlen)
+void to64frombits(char *out, const unsigned char *in, int inlen)
 /* raw bytes in quasi-big-endian order to base 64 string (NUL-terminated) */
 {
     for (; inlen >= 3; inlen -= 3)
@@ -57,7 +57,7 @@
     *out = '\0';
 }
 
-int from64tobits(char *out, const char *in)
+int from64tobits(unsigned char *out, const char *in)
 /* base 64 to raw bytes in quasi-big-endian order, returning count of bytes */
 {
     int len = 0;
