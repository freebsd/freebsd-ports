--- src/pixBufFilters.c.orig	2011-07-18 09:45:14.000000000 +0200
+++ src/pixBufFilters.c	2011-07-18 09:45:20.000000000 +0200
@@ -14,9 +14,6 @@
 #include <string.h>
 #include <assert.h>
 
-static guint32 convertRGBtoPixel ( gchar *clr );
-
-
 int isBlack ( GdkPixbuf *pixbuf, gint x, gint y, gint threshold )
 {
 	guchar *pixels;
