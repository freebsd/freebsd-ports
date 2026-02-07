--- wmgeneral/wmgeneral.c.orig	2020-09-23 12:34:09 UTC
+++ wmgeneral/wmgeneral.c
@@ -57,6 +57,9 @@
  /* X11 Variables */
 /*****************/
 
+Display		*display;
+Window		Root, iconwin, win;
+XpmIcon		wmgen;
 int			screen;
 int			x_fd;
 int			d_depth;
