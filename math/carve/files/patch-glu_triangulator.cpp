--- src/glu_triangulator.cpp.orig	2011-11-16 11:53:05.000000000 +0100
+++ src/glu_triangulator.cpp	2011-11-16 11:55:12.000000000 +0100
@@ -111,7 +111,7 @@
   size_t f = 0;
   while (f < faces.size()) {
     carve::poly::Face<3> *face = faces[f];
-    if (face->vertices.size() == 3) {
+    if (face->nVertices() == 3) {
       ++f;
       continue;
     }
@@ -123,8 +123,8 @@
     gluTessBeginPolygon(tess, (void *)this);
     gluTessBeginContour(tess);
 
-    for (size_t i = 0; i < face->vertices.size(); ++i) {
-      gluTessVertex(tess, (GLdouble *)face->vertices[i]->v.v, (GLvoid *)face->vertices[i]);
+    for (size_t i = 0; i < face->nVertices(); ++i) {
+      gluTessVertex(tess, (GLdouble *)face->vertex(i)->v.v, (GLvoid *)face->vertex(i));
     }
 
     gluTessEndContour(tess);
