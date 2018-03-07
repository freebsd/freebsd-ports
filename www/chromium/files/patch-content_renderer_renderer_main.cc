--- content/renderer/renderer_main.cc.orig	2018-02-24 16:25:14.000000000 +0100
+++ content/renderer/renderer_main.cc	2018-03-04 02:01:25.568495000 +0100
@@ -193,9 +193,13 @@
   // is OK.
   InitializeWebRtcModule();
 #endif
+#if defined(OS_BSD)
+  SkFontConfigInterface::SetGlobal(
+      new FontConfigIPC(GetSandboxFD()))->unref();
+#endif
 
   {
-#if defined(OS_WIN) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_BSD)
     // TODO(markus): Check if it is OK to unconditionally move this
     // instruction down.
     auto render_process = RenderProcessImpl::Create();
@@ -205,7 +209,7 @@
     bool run_loop = true;
     if (!no_sandbox)
       run_loop = platform.EnableSandbox();
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
     auto render_process = RenderProcessImpl::Create();
     RenderThreadImpl::Create(std::move(main_message_loop),
                              std::move(renderer_scheduler));
