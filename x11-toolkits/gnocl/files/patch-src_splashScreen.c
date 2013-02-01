--- src/splashScreen.c.orig	2013-02-01 12:39:35.000000000 +0100
+++ src/splashScreen.c	2013-02-01 12:40:09.000000000 +0100
@@ -83,7 +83,7 @@
 /**
 \brief
 **/
-static int getParams ( int objc, Tcl_Obj * const objv[], gchar *f, gchar *c, gchar *p, gchar *w )
+static void getParams ( int objc, Tcl_Obj * const objv[], gchar *f, gchar *c, gchar *p, gchar *w )
 {
 	if ( objc < 5 )
 	{
