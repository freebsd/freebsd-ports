--- ui/base/x/x11_util.h.orig	2022-08-15 13:11:31 UTC
+++ ui/base/x/x11_util.h
@@ -337,7 +337,9 @@ COMPONENT_EXPORT(UI_BASE_X) bool IsCompositingManagerP
 COMPONENT_EXPORT(UI_BASE_X) bool IsX11WindowFullScreen(x11::Window window);
 
 // Suspends or resumes the X screen saver, and returns whether the operation was
-// successful.  Must be called on the UI thread.
+// successful.  Must be called on the UI thread. If called multiple times with
+// |suspend| set to true, the screen saver is not un-suspended until this method
+// is called an equal number of times with |suspend| set to false.
 COMPONENT_EXPORT(UI_BASE_X) bool SuspendX11ScreenSaver(bool suspend);
 
 // Returns true if the window manager supports the given hint.
