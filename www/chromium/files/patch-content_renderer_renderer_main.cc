--- content/renderer/renderer_main.cc.orig	2017-12-15 02:04:18.000000000 +0100
+++ content/renderer/renderer_main.cc	2017-12-31 04:55:48.524657000 +0100
@@ -34,12 +34,19 @@
 #include "ppapi/features/features.h"
 #include "third_party/WebKit/public/platform/scheduler/renderer/renderer_scheduler.h"
 #include "third_party/skia/include/core/SkGraphics.h"
+#include "third_party/skia/include/ports/SkFontConfigInterface.h"
 #include "ui/base/ui_base_switches.h"
 
 #if defined(OS_ANDROID)
 #include "base/android/library_loader/library_loader_hooks.h"
 #endif  // OS_ANDROID
 
+#if defined(OS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "content/common/font_config_ipc_linux.h"
+#include "content/common/sandbox_linux/sandbox_linux.h"
+#endif
+
 #if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
 #include "content/common/font_config_ipc_linux.h"
 #include "content/common/sandbox_linux/sandbox_linux.h"
@@ -191,9 +198,13 @@
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
@@ -203,7 +214,7 @@
     bool run_loop = true;
     if (!no_sandbox)
       run_loop = platform.EnableSandbox();
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
     auto render_process = RenderProcessImpl::Create();
     RenderThreadImpl::Create(std::move(main_message_loop),
                              std::move(renderer_scheduler));
