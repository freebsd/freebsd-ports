--- services/service_manager/zygote/zygote_main_linux.cc.orig	2020-02-03 21:53:32 UTC
+++ services/service_manager/zygote/zygote_main_linux.cc
@@ -11,7 +11,9 @@
 #include <stddef.h>
 #include <stdint.h>
 #include <string.h>
+#if !defined(OS_BSD)
 #include <sys/prctl.h>
+#endif
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -99,6 +101,7 @@ static bool CreateInitProcessReaper(
 // created through the setuid sandbox.
 static bool EnterSuidSandbox(sandbox::SetuidSandboxClient* setuid_sandbox,
                              base::OnceClosure post_fork_parent_callback) {
+#if !defined(OS_BSD)
   DCHECK(setuid_sandbox);
   DCHECK(setuid_sandbox->IsSuidSandboxChild());
 
@@ -131,6 +134,9 @@ static bool EnterSuidSandbox(sandbox::SetuidSandboxCli
 
   CHECK(service_manager::SandboxDebugHandling::SetDumpableStatusAndHandlers());
   return true;
+#else
+  return false;
+#endif
 }
 
 static void DropAllCapabilities(int proc_fd) {
@@ -176,6 +182,7 @@ static void EnterLayerOneSandbox(service_manager::Sand
 
 bool ZygoteMain(
     std::vector<std::unique_ptr<ZygoteForkDelegate>> fork_delegates) {
+#if !defined(OS_BSD)
   sandbox::SetAmZygoteOrRenderer(true, GetSandboxFD());
 
   auto* linux_sandbox = service_manager::SandboxLinux::GetInstance();
@@ -238,6 +245,9 @@ bool ZygoteMain(
 
   // This function call can return multiple times, once per fork().
   return zygote.ProcessRequests();
+#else
+  return false;
+#endif
 }
 
 }  // namespace service_manager
