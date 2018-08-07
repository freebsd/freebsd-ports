--- content/renderer/renderer_main.cc.orig	2018-08-01 00:08:45.000000000 +0200
+++ content/renderer/renderer_main.cc	2018-08-04 19:44:52.562529000 +0200
@@ -218,7 +218,7 @@
   InitializeWebRtcModule();
 
   {
-#if defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
     // TODO(markus): Check if it is OK to unconditionally move this
     // instruction down.
     auto render_process = RenderProcessImpl::Create();
@@ -228,7 +228,7 @@
     bool run_loop = true;
     if (!no_sandbox)
       run_loop = platform.EnableSandbox();
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
     auto render_process = RenderProcessImpl::Create();
     RenderThreadImpl::Create(std::move(main_message_loop),
                              std::move(main_thread_scheduler));
