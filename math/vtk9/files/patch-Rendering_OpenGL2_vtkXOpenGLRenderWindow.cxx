--- Rendering/OpenGL2/vtkXOpenGLRenderWindow.cxx.orig	2020-06-26 13:24:40 UTC
+++ Rendering/OpenGL2/vtkXOpenGLRenderWindow.cxx
@@ -61,10 +61,22 @@ typedef ptrdiff_t GLsizeiptr;
 
 #include <sstream>
 
+// Patch from upstream b3b088e8
+#include <X11/Xatom.h>
+#include <X11/cursorfont.h>
+
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
-#include <X11/cursorfont.h>
 
+/*
+ * Work-around to get forward declarations of C typedef of anonymous
+ * structs working. We do not want to include XUtil.h in the header as
+ * it populates the global namespace.
+ */
+struct vtkXVisualInfo : public XVisualInfo
+{
+};
+
 #define GLX_CONTEXT_MAJOR_VERSION_ARB 0x2091
 #define GLX_CONTEXT_MINOR_VERSION_ARB 0x2092
 typedef GLXContext (*glXCreateContextAttribsARBProc)(
@@ -224,7 +236,7 @@ int XEventTypeEquals(Display*, XEvent* event, XPointer
   return event->type == EventType;
 }
 
-XVisualInfo* vtkXOpenGLRenderWindow::GetDesiredVisualInfo()
+vtkXVisualInfo* vtkXOpenGLRenderWindow::GetDesiredVisualInfo()
 {
   XVisualInfo* v = nullptr;
 
@@ -258,7 +270,7 @@ XVisualInfo* vtkXOpenGLRenderWindow::GetDesiredVisualI
       vtkErrorMacro(<< "Could not find a decent visual\n");
     }
   }
-  return (v);
+  return reinterpret_cast<vtkXVisualInfo*>(v);
 }
 
 vtkXOpenGLRenderWindow::vtkXOpenGLRenderWindow()
