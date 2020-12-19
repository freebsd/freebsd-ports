--- src/3rdparty/chromium/content/browser/utility_process_host.cc.orig	2020-11-07 01:22:36 UTC
+++ src/3rdparty/chromium/content/browser/utility_process_host.cc
@@ -247,7 +247,7 @@ UtilityProcessHost::UtilityProcessHost()
 
 UtilityProcessHost::UtilityProcessHost(std::unique_ptr<Client> client)
     : sandbox_type_(service_manager::SandboxType::kUtility),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
