--- ../../work.orig/nylon-0.3/err.c	Mon Oct 21 17:54:24 2002
+++ err.c	Mon Oct 21 17:56:03 2002
@@ -16,7 +16,7 @@
 
 extern int verbose;
 
-char nylon_err[] = { "Error in receiving",         /* ERROR_RECV    */
+char *nylon_err[] = { "Error in receiving",         /* ERROR_RECV    */
 		     "Error in sending",           /* ERROR_SEND    */
 		     "Error in header",            /* ERROR_HEAD    */
 		     "Error in address",           /* ERROR_ADDR    */
@@ -55,10 +55,10 @@
 #else
 	va_start(ap);
 #endif /* __STDC__ */	
-	if (fmt && (level <= verbose) && errn < NERRS && errn >= 0) {
+	if (fmt && (level <= verbose) && errn < NERRS && errn > 0) {
 		fprintf(stderr, "nylon: [error] ");
 		vfprintf(stderr, fmt, ap);
-		fprintf(stderr, "%s", nylon_err + errn);
+		fprintf(stderr, "%s", nylon_err[errn - 1]);
 	}
 	va_end(ap);
 }
