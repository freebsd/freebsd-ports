--- src/3rdparty/chromium/content/browser/sandbox_host_linux.cc.orig	2022-02-07 13:39:41 UTC
+++ src/3rdparty/chromium/content/browser/sandbox_host_linux.cc
@@ -45,6 +45,7 @@ void SandboxHostLinux::Init() {
   // Instead, it replies on a temporary socket provided by the caller.
   PCHECK(0 == shutdown(browser_socket, SHUT_WR)) << "shutdown";
 
+#if !defined(OS_BSD) 
   int pipefds[2];
   CHECK(0 == pipe(pipefds));
   const int child_lifeline_fd = pipefds[0];
@@ -55,6 +56,7 @@ void SandboxHostLinux::Init() {
   ipc_thread_ = std::make_unique<base::DelegateSimpleThread>(
       ipc_handler_.get(), "sandbox_ipc_thread");
   ipc_thread_->Start();
+#endif
 }
 
 }  // namespace content
