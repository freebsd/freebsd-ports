--- tetrahedron.h.orig
+++ tetrahedron.h
@@ -83,7 +83,7 @@
     float scale_factor;
     float wg_x;
     float wdecal;
-    GLfloat light_position[];
+    GLfloat light_position[4];
 
     GLfloat anag_x;
     GLfloat anag_y;
