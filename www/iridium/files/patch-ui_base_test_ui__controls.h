--- ui/base/test/ui_controls.h.orig	2025-02-22 18:06:53 UTC
+++ ui/base/test/ui_controls.h
@@ -184,7 +184,7 @@ bool SendTouchEventsNotifyWhenDone(int action,
                                    base::OnceClosure task);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Forces the platform implementation to use screen coordinates, even if they're
 // not really available, the next time that ui_controls::SendMouseMove() or
 // ui_controls::SendMouseMoveNotifyWhenDone() is called, or some other method
