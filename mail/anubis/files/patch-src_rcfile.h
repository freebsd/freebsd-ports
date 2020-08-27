--- src/rcfile.h.orig	2020-08-27 18:24:43 UTC
+++ src/rcfile.h
@@ -213,7 +213,7 @@ typedef void (*RC_ERROR_PRINTER) (void *data,
 				  const char *fmt, va_list ap);
 
 /* Global data */
-struct rc_loc rc_locus;
+extern struct rc_loc rc_locus;
 
 /* Function declarations */
 void verbatim (void);
