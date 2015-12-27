--- break_jsteg.c.orig	2004-08-29 23:11:00 UTC
+++ break_jsteg.c
@@ -162,7 +162,7 @@ break_jsteg_prepare(char *filename, shor
 	jstegob->skip = bytes - sizeof(jstegob->coeff);
 
 	if (jsbits < max || off + jsbits > bits) {
-		warnx("%s: bad size in bits, %d", __FUNCTION__, bits);
+		warnx("break_jsteg_prepare: bad size in bits, %d", bits);
 		return (NULL);
 	}
 
