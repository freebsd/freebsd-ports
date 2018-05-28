--- VTK/Rendering/VolumeOpenGL2/vtkOpenGLProjectedTetrahedraMapper.cxx.orig	2018-05-27 19:37:01.700537000 +0700
+++ VTK/Rendering/VolumeOpenGL2/vtkOpenGLProjectedTetrahedraMapper.cxx	2018-05-27 19:37:40.189362000 +0700
@@ -1100,7 +1100,7 @@
                         static_cast<GLuint>(this->VBO->VertexCount - 1),
                         static_cast<GLsizei>(this->Tris.IBO->IndexCount),
                         GL_UNSIGNED_INT,
-                        reinterpret_cast<const GLvoid *>(NULL));
+                        nullptr);
     this->Tris.IBO->Release();
     this->Tris.VAO->Release();
     this->VBO->Release();
