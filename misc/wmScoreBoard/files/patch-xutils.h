--- xutils.h.orig	2022-11-07 09:20:05 UTC
+++ xutils.h
@@ -15,11 +15,11 @@ typedef struct {
  *   Global variables
  */
 
-Display  *display;
-Window   Root;
-Window   iconwin, win;
-int      screen; 
-int      DisplayDepth;
+extern Display  *display;
+extern Window   Root;
+extern Window   iconwin, win;
+extern int      screen; 
+extern int      DisplayDepth;
 
 /*
  *   Function Prototypes
