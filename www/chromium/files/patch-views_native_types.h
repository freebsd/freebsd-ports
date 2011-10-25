--- views/native_types.h.orig	2011-10-07 11:32:08.000000000 +0300
+++ views/native_types.h	2011-10-08 22:57:20.811082782 +0300
@@ -8,7 +8,7 @@
 
 #include "ui/gfx/native_widget_types.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 typedef union _GdkEvent GdkEvent;
 #endif
 #if defined(USE_X11)
@@ -44,7 +44,7 @@
 typedef aura::Event* NativeEvent;
 #elif defined(OS_WIN)
 typedef MSG NativeEvent;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #if defined(USE_WAYLAND)
 typedef ui::WaylandEvent* NativeEvent;
