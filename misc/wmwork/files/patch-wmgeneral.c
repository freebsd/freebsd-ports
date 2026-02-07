--- wmgeneral.c.orig	2002-10-17 19:12:33 UTC
+++ wmgeneral.c
@@ -74,6 +74,7 @@
  /* X11 Variables */
 /*****************/
 
+Display		*display;
 Window		Root;
 int			screen;
 int			x_fd;
