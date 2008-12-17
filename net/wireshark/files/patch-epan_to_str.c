--- epan/to_str.c.orig	2008-12-17 00:32:48.000000000 -0500
+++ epan/to_str.c	2008-12-16 21:00:31.000000000 -0500
@@ -368,6 +368,9 @@ time_secs_to_str_buf(gint32 time, guint3
   const gchar *msign = "";
   gboolean do_comma = FALSE;
 
+#ifndef G_MININT32
+#define G_MININT32 G_MININT
+#endif
   if(time == G_MININT32) {	/* That Which Shall Not Be Negated */
     g_snprintf(buf, buf_len, "Unable to cope with time value %d", time);
     return;
