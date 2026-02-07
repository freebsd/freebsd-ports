Description: Protect some macro parameters with parentheses.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- lib/md5.c.orig
+++ lib/md5.c
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
