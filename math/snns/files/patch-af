--- xgui/sources/ui_main.c.orig	Sat Dec  4 13:08:46 1999
+++ xgui/sources/ui_main.c	Sat Dec  4 13:08:04 1999
@@ -329,8 +329,10 @@
 
   UPDATE   : 1.4.1990
 ******************************************************************************/
+#include <floatingpoint.h>
 void main (int argc, char **argv)
 {
+    fpsetmask(0);
     ui_toplevel = XtAppInitialize(&ui_appContext, "Popup", NULL, ZERO,
 				  (int *) &argc, argv, fallback_resources, 
 				  NULL, ZERO);
