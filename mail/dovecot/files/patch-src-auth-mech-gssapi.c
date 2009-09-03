--- src/auth/mech-gssapi.c.orig	2009-08-15 03:14:11.000000000 +1000
+++ src/auth/mech-gssapi.c	2009-08-29 07:02:43.000000000 +1000
@@ -218,6 +218,10 @@
 	const unsigned char *c = data;
 	unsigned int i;
 
+	/* apparently all names end with NUL? */
+	if (len > 0 && c[len-1] == '\0')
+		len--;
+
 	for (i = 0; i < len; i++) {
 		if (c[i] == '\0')
 			return TRUE;
