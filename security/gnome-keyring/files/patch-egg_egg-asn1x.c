--- egg/egg-asn1x.c.orig	2010-10-19 06:11:38.000000000 +0400
+++ egg/egg-asn1x.c	2013-11-04 22:37:43.000000000 +0400
@@ -1988,8 +1988,8 @@
 	guchar buf[sizeof (gulong)];
 	gint bytes, i, off;
 
-	for (i = 0; i < sizeof (ulong); ++i) {
-		off = sizeof (ulong) - (i + 1);
+	for (i = 0; i < sizeof (gulong); ++i) {
+		off = sizeof (gulong) - (i + 1);
 		buf[i] = (value >> (off * 8)) & 0xFF;
 	}
 
@@ -3746,7 +3746,7 @@
  * TIME PARSING
  */
 
-glong
+time_t
 egg_asn1x_parse_time_general (const gchar *time, gssize n_time)
 {
 	gboolean ret;
@@ -3777,7 +3777,7 @@
 	return value;
 }
 
-glong
+time_t
 egg_asn1x_parse_time_utc (const gchar *time, gssize n_time)
 {
 	gboolean ret;
