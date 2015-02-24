--- VTK/Rendering/OpenGL/vtkXOpenGLRenderWindow.cxx	2014-01-22 16:55:41.000000000 +0100
+++ VTK/Rendering/OpenGL/vtkXOpenGLRenderWindow.cxx	2014-12-20 01:00:32.000000000 +0100
@@ -27,7 +27,7 @@
 
 // define GLX_GLXEXT_LEGACY to prevent glx.h to include glxext.h provided by
 // the system
-//#define GLX_GLXEXT_LEGACY
+#define GLX_GLXEXT_LEGACY
 #include "GL/glx.h"
 
 #include "vtkgl.h"
