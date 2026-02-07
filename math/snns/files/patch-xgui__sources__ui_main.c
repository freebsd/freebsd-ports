--- xgui/sources/ui_main.c.orig	2008-04-21 16:56:25.000000000 +0900
+++ xgui/sources/ui_main.c	2012-10-24 04:51:45.000000000 +0900
@@ -329,8 +329,10 @@
 
   UPDATE   : 1.4.1990
 ******************************************************************************/
-void main (int argc, char **argv)
+#include <floatingpoint.h>
+int main (int argc, char **argv)
 {
+    fpsetmask(0);
     ui_toplevel = XtAppInitialize(&ui_appContext, "Popup", NULL, ZERO,
 				  (int *) &argc, argv, fallback_resources, 
 				  NULL, ZERO);
