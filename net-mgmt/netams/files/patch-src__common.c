--- ./src/common.c	Fri Apr 21 10:25:11 2006
+++ ./src/common.c	Wed Jun 14 13:15:26 2006
@@ -179,11 +179,21 @@
   
 	if (flag_syslog) { bzero(str2log2, 256); bzero(str2log1, 256+64); }
 
-	va_start(ap, fmt);
-	if (flag_nodaemon && !flag_quiet) vfprintf(stdout, fmt, ap);
-	if (flag_log) vfprintf(LOGFILE, fmt, ap);
-	if (flag_syslog) vsnprintf(str2log2,256, fmt, ap);
-	va_end(ap);
+	if (flag_nodaemon && !flag_quiet) {
+		va_start(ap, fmt);
+		vfprintf(stdout, fmt, ap);
+		va_end(ap);
+	}	
+	if (flag_log) {
+		va_start(ap, fmt);
+		vfprintf(LOGFILE, fmt, ap);
+		va_end(ap);
+	}
+	if (flag_syslog) {
+		va_start(ap, fmt);
+		vsnprintf(str2log2,256, fmt, ap);
+		va_end(ap);
+	}
 
 	if (flag_syslog) {
 	    snprintf(str2log1,256+64,"%s:%u %s", where, id, str2log2);
