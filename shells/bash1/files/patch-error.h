--- error.h.orig	Fri Aug 29 12:24:24 2003
+++ error.h	Fri Aug 29 12:25:40 2003
@@ -25,10 +25,10 @@
 extern void file_error ();
 
 /* Report a programmer's error, and abort.  Pass REASON, and ARG1 ... ARG5. */
-extern void programming_error ();
+extern void programming_error (char *, ...);
 
 /* General error reporting.  Pass FORMAT and ARG1 ... ARG5. */
-extern void report_error ();
+extern void report_error (char *, ...);
 
 /* Report an unrecoverable error and exit.  Pass FORMAT and ARG1 ... ARG5. */
-extern void fatal_error ();
+extern void fatal_error (char *, ...);
