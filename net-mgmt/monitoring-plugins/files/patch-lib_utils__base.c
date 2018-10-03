--- lib/utils_base.c.orig	2016-11-29 08:45:08 UTC
+++ lib/utils_base.c
@@ -87,10 +87,13 @@ void _get_monitoring_plugin( monitoring_
 void
 die (int result, const char *fmt, ...)
 {
-	va_list ap;
-	va_start (ap, fmt);
-	vprintf (fmt, ap);
-	va_end (ap);
+	if(fmt!=NULL) {
+		va_list ap;
+		va_start (ap, fmt);
+		vprintf (fmt, ap);
+		va_end (ap);
+	}
+
 	if(this_monitoring_plugin!=NULL) {
 		np_cleanup();
 	}
