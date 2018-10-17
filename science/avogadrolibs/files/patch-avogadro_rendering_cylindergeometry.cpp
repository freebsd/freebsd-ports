--- avogadro/rendering/cylindergeometry.cpp.orig	2018-10-16 22:23:29 UTC
+++ avogadro/rendering/cylindergeometry.cpp
@@ -223,7 +223,7 @@ void CylinderGeometry::render(const Came
   // Render the loaded spheres using the shader and bound VBO.
   glDrawRangeElements(GL_TRIANGLES, 0, static_cast<GLuint>(d->numberOfVertices),
                       static_cast<GLsizei>(d->numberOfIndices), GL_UNSIGNED_INT,
-                      reinterpret_cast<const GLvoid*>(NULL));
+                      (const GLvoid*)nullptr);
 
   d->vbo.release();
   d->ibo.release();
