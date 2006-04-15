--- break_jsteg.c.orig	Sun Aug 29 20:11:00 2004
+++ break_jsteg.c	Sat Apr 15 00:05:52 2006
@@ -162,7 +162,7 @@
 	jstegob->skip = bytes - sizeof(jstegob->coeff);
 
 	if (jsbits < max || off + jsbits > bits) {
-		warnx("%s: bad size in bits, %d", __FUNCTION__, bits);
+		warnx("break_jsteg_prepare: bad size in bits, %d", bits);
 		return (NULL);
 	}
 
