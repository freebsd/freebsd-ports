--- Rendering/OpenGL/vtkXOpenGLRenderWindow.cxx.orig	2015-03-03 20:37:14 UTC
+++ Rendering/OpenGL/vtkXOpenGLRenderWindow.cxx
@@ -386,7 +386,7 @@ XVisualInfo *vtkXOpenGLRenderWindow::Get
 
 vtkXOpenGLRenderWindow::vtkXOpenGLRenderWindow()
 {
-  this->ParentId = static_cast<Window>(NULL);
+  this->ParentId = static_cast<Window>(0);
   this->ScreenSize[0] = 0;
   this->ScreenSize[1] = 0;
   this->OwnDisplay = 0;
@@ -394,8 +394,8 @@ vtkXOpenGLRenderWindow::vtkXOpenGLRender
   this->ForceMakeCurrent = 0;
   this->UsingHardware = 0;
   this->DisplayId = static_cast<Display *>(NULL);
-  this->WindowId = static_cast<Window>(NULL);
-  this->NextWindowId = static_cast<Window>(NULL);
+  this->WindowId = static_cast<Window>(0);
+  this->NextWindowId = static_cast<Window>(0);
   this->ColorMap = static_cast<Colormap>(0);
   this->OwnWindow = 0;
 
@@ -776,7 +776,7 @@ void vtkXOpenGLRenderWindow::DestroyWind
   if (this->OwnWindow && this->DisplayId && this->WindowId)
     {
     XDestroyWindow(this->DisplayId,this->WindowId);
-    this->WindowId = static_cast<Window>(NULL);
+    this->WindowId = static_cast<Window>(0);
     }
 
   // if we create the display, we'll delete it
@@ -1168,7 +1168,7 @@ void vtkXOpenGLRenderWindow::WindowRemap
 
   // set the default windowid
   this->WindowId = this->NextWindowId;
-  this->NextWindowId = static_cast<Window>(NULL);
+  this->NextWindowId = static_cast<Window>(0);
 
   // set everything up again
   this->Initialize();
