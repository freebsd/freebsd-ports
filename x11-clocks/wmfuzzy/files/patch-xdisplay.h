--- xdisplay.h.orig	Sun Nov 21 17:40:24 2004
+++ xdisplay.h	Sun Nov 21 17:42:34 2004
@@ -11,6 +11,7 @@
  * functions in display.h.
  */
 #include <ctype.h>
+#include <stddef.h>
 
 /* Set up code. Must be called prior to x_main_loop. */
 void display_initialise(int argc, char* argv[]);
