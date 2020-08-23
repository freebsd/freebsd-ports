--- xutils.h.orig	1999-03-27 06:46:38 UTC
+++ xutils.h
@@ -18,11 +18,11 @@ typedef struct {
 /*
  *   Global variable
  */
-Display		*display;
-Window          Root;
-Window          iconwin, win;
-int             screen; 
-int             DisplayDepth;
+extern Display		*display;
+extern Window          Root;
+extern Window          iconwin, win;
+extern int             screen; 
+extern int             DisplayDepth;
 
 
 
