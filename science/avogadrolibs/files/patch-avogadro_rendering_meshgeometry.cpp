--- avogadro/rendering/meshgeometry.cpp.orig	2018-10-16 22:24:31 UTC
+++ avogadro/rendering/meshgeometry.cpp
@@ -171,7 +171,7 @@ void MeshGeometry::render(const Camera& 
   glDrawRangeElements(GL_TRIANGLES, 0,
                       static_cast<GLuint>(d->numberOfVertices - 1),
                       static_cast<GLsizei>(d->numberOfIndices), GL_UNSIGNED_INT,
-                      reinterpret_cast<const GLvoid*>(NULL));
+                      (const GLvoid*)nullptr);
 
   d->vbo.release();
   d->ibo.release();
