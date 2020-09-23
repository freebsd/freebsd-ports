--- wmgeneral/wmgeneral.h.orig	2020-09-23 12:34:16 UTC
+++ wmgeneral/wmgeneral.h
@@ -36,9 +36,9 @@ typedef struct {
  /* Global variable */
 /*******************/
 
-Display		*display;
-Window          Root, iconwin, win;
-XpmIcon		wmgen;
+extern Display		*display;
+extern Window          Root, iconwin, win;
+extern XpmIcon		wmgen;
 
   /***********************/
  /* Function Prototypes */
