--- VTK/Rendering/OpenGL2/vtkOpenGLRenderUtilities.cxx.orig	2018-05-27 16:31:22.687702000 +0700
+++ VTK/Rendering/OpenGL2/vtkOpenGLRenderUtilities.cxx	2018-05-27 16:32:03.881401000 +0700
@@ -93,8 +93,7 @@
   vtkNew<vtkOpenGLBufferObject> ibo;
   vao->Bind();
   ibo->Upload(iboData, numIndices, vtkOpenGLBufferObject::ElementArrayBuffer);
-  glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT,
-    reinterpret_cast<const GLvoid *>(NULL));
+  glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, nullptr);
   ibo->Release();
   ibo->ReleaseGraphicsResources();
   vao->RemoveAttributeArray("vertexMC");
