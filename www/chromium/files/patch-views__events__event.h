--- views/events/event.h.orig	2011-09-10 15:38:07.000000000 +0300
+++ views/events/event.h	2011-09-10 15:38:29.000000000 +0300
@@ -90,7 +90,7 @@
 #if defined(OS_WIN)
   // Returns the EventFlags in terms of windows flags.
   int GetWindowsFlags() const;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   // Get the views::Event flags from a native GdkEvent.
   static int GetFlagsFromGdkEvent(NativeEvent native_event);
 #endif
