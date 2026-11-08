--- lib/utils_base.c.orig	2023-01-13 16:19:35 UTC
+++ lib/utils_base.c
@@ -88,7 +88,9 @@ die (int result, const char *fmt, ...)
 {
 	va_list ap;
 	va_start (ap, fmt);
-	vprintf (fmt, ap);
+	if (fmt != NULL) {
+		vprintf (fmt, ap);
+	}
 	va_end (ap);
 	if(this_nagios_plugin) {
 		np_cleanup();
