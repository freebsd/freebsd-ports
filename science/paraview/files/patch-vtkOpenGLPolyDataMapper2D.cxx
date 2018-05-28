--- VTK/Rendering/OpenGL2/vtkOpenGLPolyDataMapper2D.cxx.orig	2018-05-27 16:27:25.256918000 +0700
+++ VTK/Rendering/OpenGL2/vtkOpenGLPolyDataMapper2D.cxx	2018-05-27 16:29:21.344983000 +0700
@@ -860,7 +860,7 @@
                         static_cast<GLuint>(this->VBO->VertexCount - 1),
                         static_cast<GLsizei>(this->Points.IBO->IndexCount),
                         GL_UNSIGNED_INT,
-                        reinterpret_cast<const GLvoid *>(NULL));
+                        nullptr);
     this->Points.IBO->Release();
     this->PrimitiveIDOffset += (int)this->Points.IBO->IndexCount;
   }
@@ -881,7 +881,7 @@
                           static_cast<GLuint>(this->VBO->VertexCount - 1),
                           static_cast<GLsizei>(this->Lines.IBO->IndexCount),
                           GL_UNSIGNED_INT,
-                          reinterpret_cast<const GLvoid *>(NULL));
+                          nullptr);
       this->Lines.IBO->Release();
     }
     this->PrimitiveIDOffset += (int)this->Lines.IBO->IndexCount/2;
@@ -899,7 +899,7 @@
                           static_cast<GLuint>(this->VBO->VertexCount - 1),
                           static_cast<GLsizei>(this->Tris.IBO->IndexCount),
                           GL_UNSIGNED_INT,
-                          reinterpret_cast<const GLvoid *>(NULL));
+                          nullptr);
       this->Tris.IBO->Release();
       this->PrimitiveIDOffset += (int)this->Tris.IBO->IndexCount/3;
     }
@@ -916,7 +916,7 @@
                           static_cast<GLuint>(this->VBO->VertexCount - 1),
                           static_cast<GLsizei>(this->TriStrips.IBO->IndexCount),
                           GL_UNSIGNED_INT,
-                          reinterpret_cast<const GLvoid *>(NULL));
+                          nullptr);
       this->TriStrips.IBO->Release();
     }
   }
