--- content/renderer/render_thread_impl.cc.orig	2015-05-13 18:35:46.000000000 -0400
+++ content/renderer/render_thread_impl.cc	    2015-05-20 15:46:14.175833000 -0400
@@ -673,7 +673,7 @@
                   static_cast<unsigned>(compositor_raster_threads_.size() + 1))
                   .c_str()));
       raster_thread->Start();
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
       if (!command_line.HasSwitch(
               switches::kUseNormalPriorityForTileTaskWorkerThreads)) {
         raster_thread->SetThreadPriority(base::ThreadPriority::BACKGROUND);
