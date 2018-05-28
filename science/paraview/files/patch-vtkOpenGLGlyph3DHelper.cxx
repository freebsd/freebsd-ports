--- VTK/Rendering/OpenGL2/vtkOpenGLGlyph3DHelper.cxx.orig	2018-05-27 16:13:23.631718000 +0700
+++ VTK/Rendering/OpenGL2/vtkOpenGLGlyph3DHelper.cxx	2018-05-27 16:21:35.310777000 +0700
@@ -449,7 +449,7 @@
                         static_cast<GLuint>(this->VBO->VertexCount - 1),
                         static_cast<GLsizei>(this->Primitives[PrimitiveTris].IBO->IndexCount),
                         GL_UNSIGNED_INT,
-                        reinterpret_cast<const GLvoid *>(NULL));
+                        nullptr);
   }
   if (primed)
   {
@@ -579,7 +579,7 @@
     glDrawElementsInstancedARB(GL_TRIANGLES,
       static_cast<GLsizei>(this->Primitives[PrimitiveTris].IBO->IndexCount),
       GL_UNSIGNED_INT,
-      reinterpret_cast<const GLvoid *>(NULL),
+      nullptr,
       numPts);
   }
 #endif
