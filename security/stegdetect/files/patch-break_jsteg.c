--- break_jsteg.c	Fri Dec 21 01:11:32 2001
+++ /tmp/break_jsteg.c.diff	Wed Dec 29 03:32:38 2004
@@ -162,7 +162,7 @@
 	jstegob->skip = bytes - sizeof(jstegob->coeff);
 
 	if (jsbits < max || off + jsbits > bits) {
-		warnx(__FUNCTION__": bad size in bits, %d", bits);
+		warnx("break_jsteg_prepare: bad size in bits, %d", bits);
 		return (NULL);
 	}
 
