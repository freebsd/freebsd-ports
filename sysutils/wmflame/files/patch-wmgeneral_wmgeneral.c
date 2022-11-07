--- ../wmgeneral/wmgeneral.c.orig	1999-07-12 03:30:14 UTC
+++ ../wmgeneral/wmgeneral.c
@@ -57,6 +57,9 @@
  /* X11 Variables */
 /*****************/
 
+Display		*display;
+Window		Root, iconwin, win;
+XpmIcon		wmgen;
 int			screen;
 int			x_fd;
 int			d_depth;
