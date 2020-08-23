--- xutils.c.orig	1999-03-27 06:46:38 UTC
+++ xutils.c
@@ -39,7 +39,11 @@
 #include <X11/extensions/shape.h>
 #include "xutils.h"
 
-
+Display		*display;
+Window		Root;
+Window		iconwin, win;
+int		screen;
+int		DisplayDepth;
 
 /*
  *   X11 Variables 
