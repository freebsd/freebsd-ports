diff -urN -x .svn ../../branches/vendor/mhash/lib/gosthash.c ./lib/gosthash.c
--- ../../branches/vendor/mhash/lib/gosthash.c	2008-01-16 14:26:51.000000000 +0200
+++ ./lib/gosthash.c	2008-01-16 15:12:01.000000000 +0200
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
