--- content/browser/browser_main_loop.cc.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/browser/browser_main_loop.cc	2016-08-18 02:39:59.331387000 +0300
@@ -203,7 +203,7 @@
 namespace content {
 namespace {
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 void SetupSandbox(const base::CommandLine& parsed_command_line) {
   TRACE_EVENT0("startup", "SetupSandbox");
   base::FilePath sandbox_binary;
@@ -467,7 +467,7 @@
   TRACE_EVENT0("startup", "BrowserMainLoop::EarlyInitialization");
   TRACK_SCOPED_REGION("Startup", "BrowserMainLoop::EarlyInitialization");
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   // No thread should be created before this call, as SetupSandbox()
   // will end-up using fork().
   SetupSandbox(parsed_command_line_);
@@ -507,7 +507,7 @@
   // We use quite a few file descriptors for our IPC, and the default limit on
   // the Mac is low (256), so bump it up.
   base::SetFdLimit(1024);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Same for Linux. The default various per distro, but it is 1024 on Fedora.
   // Low soft limits combined with liberal use of file descriptors means power
   // users can easily hit this limit with many open tabs. Bump up the limit to
