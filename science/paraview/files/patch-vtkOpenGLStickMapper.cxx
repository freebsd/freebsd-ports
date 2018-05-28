--- VTK/Rendering/OpenGL2/vtkOpenGLStickMapper.cxx.orig	2018-05-27 16:48:40.625194000 +0700
+++ VTK/Rendering/OpenGL2/vtkOpenGLStickMapper.cxx	2018-05-27 16:48:53.507986000 +0700
@@ -614,7 +614,7 @@
                         static_cast<GLuint>(this->VBO->VertexCount - 1),
                         static_cast<GLsizei>(this->Primitives[PrimitiveTris].IBO->IndexCount),
                         GL_UNSIGNED_INT,
-                        reinterpret_cast<const GLvoid *>(NULL));
+                        nullptr);
     this->Primitives[PrimitiveTris].IBO->Release();
   }
 }
