--- views/native_types.h.orig	2011-09-10 16:05:08.000000000 +0300
+++ views/native_types.h	2011-09-10 16:05:37.000000000 +0300
@@ -8,7 +8,7 @@
 
 #include "ui/gfx/native_widget_types.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 typedef union _GdkEvent GdkEvent;
 #endif
 #if defined(USE_X11)
@@ -32,7 +32,7 @@
 #if defined(OS_WIN)
 typedef MSG NativeEvent;
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 typedef GdkEvent* NativeEvent;
 #endif
 #if defined(USE_X11)
