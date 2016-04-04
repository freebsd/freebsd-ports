--- installwatch.c.orig	2001-12-22 23:55:11 UTC
+++ installwatch.c
@@ -574,7 +574,7 @@ int open(const char *pathname, int flags
 
 	REFCOUNT;
 	va_start(ap, flags);
-	mode = va_arg(ap, mode_t);
+	mode = va_arg(ap, int);
 	va_end(ap);
 	canonicalize(pathname, canonic);
 
