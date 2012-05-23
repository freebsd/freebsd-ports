--- src/console_output.h.orig	2010-04-11 23:46:54.000000000 +0900
+++ src/console_output.h	2012-05-15 04:21:37.000000000 +0900
@@ -21,7 +21,7 @@
 #ifndef GXINE_CONSOLE_OUTPUT_H
 #define GXINE_CONSOLE_OUTPUT_H
 
-#include <glib/gmessages.h>
+#include <glib.h>
 
 void console_output_init (void);
 
