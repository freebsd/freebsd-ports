--- content/browser/browser_main_loop.cc.orig	2016-12-15 13:00:14.708308000 +0000
+++ content/browser/browser_main_loop.cc	2016-12-15 13:05:18.516426000 +0000
@@ -196,6 +196,10 @@
 #include "gpu/vulkan/vulkan_implementation.h"
 #endif
 
+#if defined(OS_BSD)
+#include "content/common/child_process_sandbox_support_impl_linux.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -204,7 +208,7 @@
 namespace content {
 namespace {
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SetupSandbox(const base::CommandLine& parsed_command_line) {
   TRACE_EVENT0("startup", "SetupSandbox");
   if (parsed_command_line.HasSwitch(switches::kNoZygote)) {
@@ -475,10 +479,15 @@
 void BrowserMainLoop::EarlyInitialization() {
   TRACE_EVENT0("startup", "BrowserMainLoop::EarlyInitialization");
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // No thread should be created before this call, as SetupSandbox()
   // will end-up using fork().
   SetupSandbox(parsed_command_line_);
+#elif defined(OS_BSD)
+  RenderSandboxHostLinux::GetInstance()->Init();
+  base::FileHandleMappingVector fds_to_map;
+  const int sfd = RenderSandboxHostLinux::GetInstance()->GetRendererSocket();
+  fds_to_map.push_back(std::make_pair(sfd, GetSandboxFD()));
 #endif
 
 #if defined(USE_X11)
