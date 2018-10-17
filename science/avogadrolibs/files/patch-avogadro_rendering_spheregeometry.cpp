--- avogadro/rendering/spheregeometry.cpp.orig	2018-10-16 22:26:03 UTC
+++ avogadro/rendering/spheregeometry.cpp
@@ -196,7 +196,7 @@ void SphereGeometry::render(const Camera
   // Render the loaded spheres using the shader and bound VBO.
   glDrawRangeElements(GL_TRIANGLES, 0, static_cast<GLuint>(d->numberOfVertices),
                       static_cast<GLsizei>(d->numberOfIndices), GL_UNSIGNED_INT,
-                      reinterpret_cast<const GLvoid*>(NULL));
+                      (const GLvoid*)nullptr);
 
   d->vbo.release();
   d->ibo.release();
