--- mozilla/toolkit/xre/nsAppRunner.cpp~
+++ mozilla/toolkit/xre/nsAppRunner.cpp
@@ -3819,7 +3819,7 @@ XREMain::XRE_main(int argc, char* argv[]
   ScopedLogging log;
 
 #if defined(MOZ_WIDGET_GTK2)
-#ifdef MOZ_MEMORY
+#if defined(MOZ_MEMORY) || defined(__FreeBSD__)
   // Disable the slice allocator, since jemalloc already uses similar layout
   // algorithms, and using a sub-allocator tends to increase fragmentation.
   // This must be done before g_thread_init() is called.
