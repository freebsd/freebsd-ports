Description: Protect some macro parameters with parentheses.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/gosthash.c.orig
+++ lib/gosthash.c
@@ -273,22 +273,22 @@
  */
 
 #define GOST_ENCRYPT(key) \
-GOST_ENCRYPT_ROUND(key[0], key[1]) \
-GOST_ENCRYPT_ROUND(key[2], key[3]) \
-GOST_ENCRYPT_ROUND(key[4], key[5]) \
-GOST_ENCRYPT_ROUND(key[6], key[7]) \
-GOST_ENCRYPT_ROUND(key[0], key[1]) \
-GOST_ENCRYPT_ROUND(key[2], key[3]) \
-GOST_ENCRYPT_ROUND(key[4], key[5]) \
-GOST_ENCRYPT_ROUND(key[6], key[7]) \
-GOST_ENCRYPT_ROUND(key[0], key[1]) \
-GOST_ENCRYPT_ROUND(key[2], key[3]) \
-GOST_ENCRYPT_ROUND(key[4], key[5]) \
-GOST_ENCRYPT_ROUND(key[6], key[7]) \
-GOST_ENCRYPT_ROUND(key[7], key[6]) \
-GOST_ENCRYPT_ROUND(key[5], key[4]) \
-GOST_ENCRYPT_ROUND(key[3], key[2]) \
-GOST_ENCRYPT_ROUND(key[1], key[0]) \
+GOST_ENCRYPT_ROUND((key)[0], (key)[1]) \
+GOST_ENCRYPT_ROUND((key)[2], (key)[3]) \
+GOST_ENCRYPT_ROUND((key)[4], (key)[5]) \
+GOST_ENCRYPT_ROUND((key)[6], (key)[7]) \
+GOST_ENCRYPT_ROUND((key)[0], (key)[1]) \
+GOST_ENCRYPT_ROUND((key)[2], (key)[3]) \
+GOST_ENCRYPT_ROUND((key)[4], (key)[5]) \
+GOST_ENCRYPT_ROUND((key)[6], (key)[7]) \
+GOST_ENCRYPT_ROUND((key)[0], (key)[1]) \
+GOST_ENCRYPT_ROUND((key)[2], (key)[3]) \
+GOST_ENCRYPT_ROUND((key)[4], (key)[5]) \
+GOST_ENCRYPT_ROUND((key)[6], (key)[7]) \
+GOST_ENCRYPT_ROUND((key)[7], (key)[6]) \
+GOST_ENCRYPT_ROUND((key)[5], (key)[4]) \
+GOST_ENCRYPT_ROUND((key)[3], (key)[2]) \
+GOST_ENCRYPT_ROUND((key)[1], (key)[0]) \
 t = r; \
 r = l; \
 l = t;
