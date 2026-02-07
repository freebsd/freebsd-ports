--- docklib.h.orig	2020-09-17 11:03:03 UTC
+++ docklib.h
@@ -81,12 +81,12 @@ typedef struct {
  /* Global variable */
 /*******************/
 
-Display		*display;
-Window		Root;
-int			d_depth;
-GC			NormalGC;
-XpmIcon		wmgen;
-Window		iconwin, win;
+extern Display		*display;
+extern Window		Root;
+extern int		d_depth;
+extern GC		NormalGC;
+extern XpmIcon		wmgen;
+extern Window		iconwin, win;
 
   /***********************/
  /* Function Prototypes */
