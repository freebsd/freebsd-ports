--- src/pixBufFilters.c.orig	2013-02-01 12:20:37.000000000 +0100
+++ src/pixBufFilters.c	2013-02-01 12:25:56.000000000 +0100
@@ -16,6 +16,8 @@
 
 #define RADS(var) var * G_PI / 180
 
+static void countItems ( int j, int a );
+static void filter_convolute ( GdkPixbuf *pixbuf, int matrix [3][3] );
 
 typedef struct accumulator
 {
@@ -319,7 +321,7 @@
 	gint p = 0;
 	gint r, g, b, a;
 
-	g_return_if_fail ( GDK_IS_PIXBUF ( pixbuf ) );
+	g_return_val_if_fail ( GDK_IS_PIXBUF ( pixbuf ), -1 );
 
 	/* this method prevents a deferencing error */
 	k = gdk_pixbuf_get_width ( pixbuf );
@@ -384,7 +386,7 @@
 	gint p = 0;
 	gint r, g, b, a;
 
-	g_return_if_fail ( GDK_IS_PIXBUF ( pixbuf ) );
+	g_return_val_if_fail ( GDK_IS_PIXBUF ( pixbuf ) , -1 );
 
 	/* this method prevents a deferencing error */
 	k = gdk_pixbuf_get_width ( pixbuf );
@@ -430,7 +432,7 @@
 	gint p = 0;
 	gint r, g, b, a;
 
-	g_return_if_fail ( GDK_IS_PIXBUF ( pixbuf ) );
+	g_return_val_if_fail ( GDK_IS_PIXBUF ( pixbuf ), -1 );
 
 	/* this method prevents a deferencing error */
 	k = gdk_pixbuf_get_width ( pixbuf );
@@ -502,7 +504,7 @@
 	gint p = 0;
 	guchar r, g, b, a;
 
-	g_return_if_fail ( GDK_IS_PIXBUF ( pixbuf ) );
+	g_return_val_if_fail ( GDK_IS_PIXBUF ( pixbuf ), -1 );
 
 	/* this method prevents a deferencing error */
 	k = gdk_pixbuf_get_width ( pixbuf );
@@ -559,7 +561,7 @@
 
 	g_print ( "%s 1\n", __FUNCTION__ );
 
-	g_return_if_fail ( GDK_IS_PIXBUF ( pixbuf ) );
+	g_return_val_if_fail ( GDK_IS_PIXBUF ( pixbuf ), -1 );
 
 	g_print ( "%s 2\n", __FUNCTION__ );
 
@@ -629,7 +631,7 @@
 	gint p = 0;
 	gint r, g, b, a;
 
-	g_return_if_fail ( GDK_IS_PIXBUF ( pixbuf ) );
+	g_return_val_if_fail ( GDK_IS_PIXBUF ( pixbuf ), -1 );
 
 	/* this method prevents a deferencing error */
 	k = gdk_pixbuf_get_width ( pixbuf );
@@ -675,7 +677,7 @@
 	gint p = 0;
 	guchar r, g, b, a;
 
-	g_return_if_fail ( GDK_IS_PIXBUF ( pixbuf ) );
+	g_return_val_if_fail ( GDK_IS_PIXBUF ( pixbuf ), -1 );
 
 	/* this method prevents a deferencing error */
 	k = gdk_pixbuf_get_width ( pixbuf );
@@ -717,7 +719,7 @@
 	gint p = 0;
 	guchar r, g, b, a;
 
-	g_return_if_fail ( GDK_IS_PIXBUF ( pixbuf ) );
+	g_return_val_if_fail ( GDK_IS_PIXBUF ( pixbuf ), -1 );
 
 	/* this method prevents a deferencing error */
 	k = gdk_pixbuf_get_width ( pixbuf );
@@ -777,7 +779,7 @@
 \note
 \todo
 **/
-void gnoclPixBufFilters ( Tcl_Interp *interp, GdkPixbuf *pixbuf, int objc, Tcl_Obj * const objv[] )
+int gnoclPixBufFilters ( Tcl_Interp *interp, GdkPixbuf *pixbuf, int objc, Tcl_Obj * const objv[] )
 {
 
 //GdkPixbuf *pixbuf = NULL;
