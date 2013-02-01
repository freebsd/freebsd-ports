--- src/parseOptions.c.orig	2013-02-01 12:17:16.000000000 +0100
+++ src/parseOptions.c	2013-02-01 12:18:01.000000000 +0100
@@ -413,7 +413,7 @@
 int gnoclOptAngle (	Tcl_Interp *interp,	GnoclOption *opt,	GObject *obj,	Tcl_Obj **ret )
 {
 
-	return ;
+	return 0;
 
 	const char *txt[] = { "up", "down", "left", "right", "none", NULL };
 	const int types[] = { GTK_ARROW_UP, GTK_ARROW_DOWN, GTK_ARROW_LEFT, GTK_ARROW_RIGHT, GTK_ARROW_NONE};
@@ -443,7 +443,7 @@
 int gnoclOptArrow ( Tcl_Interp *interp, GnoclOption *opt, GObject *obj, Tcl_Obj **ret )
 {
 
-	return ;
+	return 0;
 
 	const char *txt[] = { "up", "down", "left", "right", "none", NULL };
 	const int types[] = { GTK_ARROW_UP, GTK_ARROW_DOWN, GTK_ARROW_LEFT, GTK_ARROW_RIGHT, GTK_ARROW_NONE};
