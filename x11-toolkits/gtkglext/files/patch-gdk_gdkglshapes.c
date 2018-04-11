index() is a function in <strings.h>

--- gdk/gdkglshapes.c.orig	2004-02-20 09:38:12 UTC
+++ gdk/gdkglshapes.c
@@ -544,7 +544,7 @@ static GLfloat idata[12][3] =
   {-Z, -X, 0}
 };
 
-static int index[20][3] =
+static int myindex[20][3] =
 {
   {0, 4, 1},
   {0, 9, 4},
@@ -574,7 +574,7 @@ icosahedron(GLenum shadeType)
   int i;
 
   for (i = 19; i >= 0; i--) {
-    drawtriangle(i, idata, index, shadeType);
+    drawtriangle(i, idata, myindex, shadeType);
   }
 }
 
