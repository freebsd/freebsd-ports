--- ./src/broker/log.c.orig	Fri May  2 20:34:44 1997
+++ ./src/broker/log.c	Fri Aug  1 13:24:58 2003
@@ -151,10 +151,28 @@
 }
 
 /* Log Something */
-int LOG_statlog(va_alist)
+#if defined(__STRICT_ANSI__)
+int LOG_statlog(char *fmt,...)
+{
+	time_t curtime;
+	unsigned int type;
+	char *outstr = NULL;
+	char *statname = NULL;
+	char *url = NULL;
+	char *gn = NULL;
+	char *gh = NULL;
+	char *gv = NULL;
+	int gid;
+	fd_t FD;
+
+    va_list ap;
+    va_start(ap,fmt);
+    va_list args;
+    va_start(args,fmt);
+#else
+int LOG_statlog(va_alist) 
 va_dcl
 {
-	va_list args;
 	time_t curtime;
 	unsigned int type;
 	char *outstr = NULL;
@@ -166,10 +184,18 @@
 	int gid;
 	fd_t FD;
 
+    va_list ap;
+    char *fmt;
+    va_list args;
+    va_start(ap);
+    fmt = va_arg(ap, char *);
+    fmt = va_arg(args, char *);
+    va_start(args);
+#endif /* __STRICT_ANSI__ */
+
 	if (!log_file)
 		return ERROR;
 
-	va_start(args);
 	type = va_arg(args, unsigned int);
 	if (LOG_do_logging(type) == TRUE) {
 		statname = va_arg(args, char *);
