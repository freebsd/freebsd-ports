--- VTK/Rendering/OpenGL2/vtkOpenGLPolyDataMapper.cxx.orig	2018-05-27 16:24:15.569847000 +0700
+++ VTK/Rendering/OpenGL2/vtkOpenGLPolyDataMapper.cxx	2018-05-27 16:24:49.235720000 +0700
@@ -2534,7 +2534,7 @@
                           static_cast<GLuint>(this->VBO->VertexCount - 1),
                           static_cast<GLsizei>(this->Primitives[i].IBO->IndexCount),
                           GL_UNSIGNED_INT,
-                          reinterpret_cast<const GLvoid *>(NULL));
+                          nullptr);
       this->Primitives[i].IBO->Release();
 
       int stride = (mode == GL_POINTS ? 1 : (mode == GL_LINES ? 2 : 3));
