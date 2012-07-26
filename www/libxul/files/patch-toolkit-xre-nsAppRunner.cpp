--- toolkit/xre/nsAppRunner.cpp~
+++ toolkit/xre/nsAppRunner.cpp
@@ -3046,7 +3046,7 @@ XRE_main(int argc, char* argv[], const n
     QApplication app(gArgc, gArgv);
 #endif
 #if defined(MOZ_WIDGET_GTK2)
-#ifdef MOZ_MEMORY
+#if defined(MOZ_MEMORY) || defined(__FreeBSD__)
     // Disable the slice allocator, since jemalloc already uses similar layout
     // algorithms, and using a sub-allocator tends to increase fragmentation.
     // This must be done before g_thread_init() is called.
