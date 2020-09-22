--- context.h.orig	2008-07-12 06:05:22 UTC
+++ context.h
@@ -81,4 +81,4 @@ struct context {
 #define X_FILE		1		/* input is a file */
 #define X_BUF		2		/* input is a buffer */
 
-struct context cx;			/* the current context */
+extern struct context cx;		/* the current context */
