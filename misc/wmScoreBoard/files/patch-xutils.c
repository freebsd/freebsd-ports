--- xutils.c.orig	2022-11-07 09:20:08 UTC
+++ xutils.c
@@ -39,6 +39,11 @@
  *   X11 Variables 
  */
 
+Display		*display;
+Window		Root;
+Window		iconwin, win;
+int		screen; 
+int		DisplayDepth;
 int		   x_fd;
 XSizeHints	mysizehints;
 XWMHints  	mywmhints;
