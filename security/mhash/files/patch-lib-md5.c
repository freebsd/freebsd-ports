diff -urN -x .svn ../../branches/vendor/mhash/lib/md5.c ./lib/md5.c
--- ../../branches/vendor/mhash/lib/md5.c	2008-01-16 14:26:51.000000000 +0200
+++ ./lib/md5.c	2008-01-16 15:11:08.000000000 +0200
@@ -140,14 +140,14 @@
 /* The four core functions - F1 is optimized somewhat */
 
 /* #define F1(x, y, z) (x & y | ~x & z) */
-#define F1(x, y, z) (z ^ (x & (y ^ z)))
-#define F2(x, y, z) F1(z, x, y)
-#define F3(x, y, z) (x ^ y ^ z)
-#define F4(x, y, z) (y ^ (x | ~z))
+#define F1(x, y, z) ((z) ^ ((x) & ((y) ^ (z))))
+#define F2(x, y, z) F1((z), (x), (y))
+#define F3(x, y, z) ((x) ^ (y) ^ (z))
+#define F4(x, y, z) ((y) ^ ((x) | ~(z)))
 
 /* This is the central step in the MD5 algorithm. */
 #define MD5STEP(f, w, x, y, z, data, s) \
-	( w += f(x, y, z) + data,  w = w<<s | w>>(32-s),  w += x )
+	( (w) += f(x, y, z) + (data),  (w) = (w)<<(s) | (w)>>(32-(s)),  (w) += (x) )
 
 /*
  * The core of the MD5 algorithm, this alters an existing MD5 hash to
