--- wmgeneral.c.orig	2003-12-02 16:45:19 UTC
+++ wmgeneral.c
@@ -55,6 +55,7 @@
  /* X11 Variables */
 /*****************/
 
+Display		*display;
 Window		Root;
 int			screen;
 int			x_fd;
