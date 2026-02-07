--- wmgeneral/wmgeneral.c.orig	2021-02-09 17:08:45 UTC
+++ wmgeneral/wmgeneral.c
@@ -55,6 +55,8 @@
  /* X11 Variables */
 /*****************/
 
+Display		*display;
+
 Window		Root;
 int			screen;
 int			x_fd;
