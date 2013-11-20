--- egg/egg-asn1x.c.orig	2010-09-04 12:08:41.000000000 +0200
+++ egg/egg-asn1x.c	2010-09-04 12:10:05.000000000 +0200
@@ -1988,8 +1988,8 @@ anode_write_integer_ulong (gulong value,
 	guchar buf[sizeof (gulong)];
 	gint bytes, i, off;
 
-	for (i = 0; i < sizeof (ulong); ++i) {
-		off = sizeof (ulong) - (i + 1);
+	for (i = 0; i < sizeof (gulong); ++i) {
+		off = sizeof (gulong) - (i + 1);
 		buf[i] = (value >> (off * 8)) & 0xFF;
 	}
 
