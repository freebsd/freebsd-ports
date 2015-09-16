--- content/renderer/render_thread_impl.cc.orig	2015-09-01 16:10:42.000000000 -0400
+++ content/renderer/render_thread_impl.cc	2015-09-03 10:37:57.364787000 -0400
@@ -768,7 +768,7 @@
   is_gather_pixel_refs_enabled_ = num_raster_threads > 1;
 
   base::SimpleThread::Options thread_options;
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   if (!command_line.HasSwitch(
           switches::kUseNormalPriorityForTileTaskWorkerThreads)) {
     thread_options.set_priority(base::ThreadPriority::BACKGROUND);
