--- Rendering/OpenGL2/vtkXOpenGLRenderWindow.h.orig	2020-06-26 13:24:40 UTC
+++ Rendering/OpenGL2/vtkXOpenGLRenderWindow.h
@@ -28,11 +28,11 @@
 #include "vtkOpenGLRenderWindow.h"
 #include "vtkRenderingOpenGL2Module.h" // For export macro
 #include <X11/Xlib.h>                  // Needed for X types used in the public interface
-#include <X11/Xutil.h>                 // Needed for X types used in the public interface
 #include <stack>                       // for ivar
 
 class vtkIdList;
 class vtkXOpenGLRenderWindowInternal;
+struct vtkXVisualInfo;
 
 class VTKRENDERINGOPENGL2_EXPORT vtkXOpenGLRenderWindow : public vtkOpenGLRenderWindow
 {
@@ -112,7 +112,7 @@ class VTKRENDERINGOPENGL2_EXPORT vtkXOpenGLRenderWindo
    */
   virtual Colormap GetDesiredColormap();
   virtual Visual* GetDesiredVisual();
-  virtual XVisualInfo* GetDesiredVisualInfo();
+  virtual vtkXVisualInfo* GetDesiredVisualInfo();
   virtual int GetDesiredDepth();
   //@}
 
