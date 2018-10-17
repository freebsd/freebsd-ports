--- avogadro/rendering/ambientocclusionspheregeometry.cpp.orig	2018-10-16 22:25:02 UTC
+++ avogadro/rendering/ambientocclusionspheregeometry.cpp
@@ -930,7 +930,7 @@ public:
     // draw
     glDrawRangeElements(GL_TRIANGLES, 0, static_cast<GLuint>(m_numVertices),
                         static_cast<GLsizei>(m_numIndices), GL_UNSIGNED_INT,
-                        reinterpret_cast<const GLvoid*>(NULL));
+                        (const GLvoid*)nullptr);
 
     m_vbo.release();
     m_ibo.release();
@@ -1004,7 +1004,7 @@ public:
     // draw
     glDrawRangeElements(GL_TRIANGLES, 0, static_cast<GLuint>(m_numVertices),
                         static_cast<GLsizei>(m_numIndices), GL_UNSIGNED_INT,
-                        reinterpret_cast<const GLvoid*>(NULL));
+                        (const GLvoid*)nullptr);
 
     m_vbo.release();
     m_ibo.release();
@@ -1326,7 +1326,7 @@ void AmbientOcclusionSphereGeometry::ren
   // Render the loaded spheres using the shader and bound VBO.
   glDrawRangeElements(GL_TRIANGLES, 0, static_cast<GLuint>(d->numberOfVertices),
                       static_cast<GLsizei>(d->numberOfIndices), GL_UNSIGNED_INT,
-                      reinterpret_cast<const GLvoid*>(NULL));
+                      (const GLvoid*)nullptr);
 
   d->vbo.release();
   d->ibo.release();
