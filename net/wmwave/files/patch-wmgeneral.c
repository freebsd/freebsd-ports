--- wmgeneral.c.orig	2022-11-06 10:29:50 UTC
+++ wmgeneral.c
@@ -65,8 +65,9 @@
 /* X11 Variables */
 /*****************/
 
+Display		*display;
 Window		Root;
-int			screen;
+extern int			screen;
 int			x_fd;
 int			d_depth;
 XSizeHints	mysizehints;
