--- VTK/Rendering/OpenGL2/vtkXOpenGLRenderWindow.cxx.orig	2018-05-27 16:56:49.463432000 +0700
+++ VTK/Rendering/OpenGL2/vtkXOpenGLRenderWindow.cxx	2018-05-27 16:58:36.068069000 +0700
@@ -333,7 +333,7 @@
 
 vtkXOpenGLRenderWindow::vtkXOpenGLRenderWindow()
 {
-  this->ParentId = static_cast<Window>(NULL);
+  this->ParentId = static_cast<Window>(0);
   this->ScreenSize[0] = 0;
   this->ScreenSize[1] = 0;
   this->OwnDisplay = 0;
@@ -341,8 +341,8 @@
   this->ForceMakeCurrent = 0;
   this->UsingHardware = 0;
   this->DisplayId = static_cast<Display *>(NULL);
-  this->WindowId = static_cast<Window>(NULL);
-  this->NextWindowId = static_cast<Window>(NULL);
+  this->WindowId = static_cast<Window>(0);
+  this->NextWindowId = static_cast<Window>(0);
   this->ColorMap = static_cast<Colormap>(0);
   this->OwnWindow = 0;
 
@@ -762,7 +762,7 @@
   if (this->OwnWindow && this->DisplayId && this->WindowId)
   {
     XDestroyWindow(this->DisplayId,this->WindowId);
-    this->WindowId = static_cast<Window>(NULL);
+    this->WindowId = static_cast<Window>(0);
   }
 
   this->CloseDisplay();
@@ -1157,7 +1157,7 @@
 
   // set the default windowid
   this->WindowId = this->NextWindowId;
-  this->NextWindowId = static_cast<Window>(NULL);
+  this->NextWindowId = static_cast<Window>(0);
 
   // set everything up again
   this->Initialize();
