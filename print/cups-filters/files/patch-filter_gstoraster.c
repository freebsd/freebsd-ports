--- filter/gstoraster.c.orig	2016-11-23 21:36:11 UTC
+++ filter/gstoraster.c
@@ -48,6 +48,8 @@ MIT Open Source License  -  http://www.o
 #include <signal.h>
 #include <errno.h>
 
+#define execvpe(a, b, c) execvp(a, b)
+
 #define PDF_MAX_CHECK_COMMENT_LINES	20
 
 typedef enum {
