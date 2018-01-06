--- src/3rdparty/chromium/content/browser/utility_process_host_impl.cc.orig	2017-01-26 00:49:13 UTC
+++ src/3rdparty/chromium/content/browser/utility_process_host_impl.cc
@@ -43,9 +43,9 @@
 #include "services/service_manager/public/cpp/interface_provider.h"
 #include "ui/base/ui_base_switches.h"
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/browser/zygote_handle_linux.h"
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include "sandbox/win/src/sandbox_policy.h"
@@ -54,11 +54,11 @@
 
 namespace content {
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 namespace {
 ZygoteHandle g_utility_zygote;
 }  // namespace
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 // NOTE: changes to this class need to be reviewed by the security team.
 class UtilitySandboxedProcessLauncherDelegate
@@ -73,10 +73,10 @@ class UtilitySandboxedProcessLauncherDel
         launch_elevated_(launch_elevated)
 #elif defined(OS_POSIX)
         env_(env)
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         ,
         no_sandbox_(no_sandbox)
-#endif  // !defined(OS_MACOSX)  && !defined(OS_ANDROID)
+#endif  // !defined(OS_MACOSX)  && !defined(OS_ANDROID) && !defined(OS_BSD)
 #endif  // OS_WIN
   {}
 
@@ -105,13 +105,13 @@ class UtilitySandboxedProcessLauncherDel
 
 #elif defined(OS_POSIX)
 
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     if (no_sandbox_ || !exposed_dir_.empty())
       return nullptr;
     return GetGenericZygote();
   }
-#endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   base::EnvironmentMap GetEnvironment() override { return env_; }
 #endif  // OS_WIN
 
@@ -126,9 +126,9 @@ class UtilitySandboxedProcessLauncherDel
   bool launch_elevated_;
 #elif defined(OS_POSIX)
   base::EnvironmentMap env_;
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   bool no_sandbox_;
-#endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 #endif  // OS_WIN
 };
 
@@ -153,7 +153,7 @@ UtilityProcessHostImpl::UtilityProcessHo
       is_batch_mode_(false),
       no_sandbox_(false),
       run_elevated_(false),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
@@ -235,13 +235,13 @@ void UtilityProcessHostImpl::SetName(con
   name_ = name;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void UtilityProcessHostImpl::EarlyZygoteLaunch() {
   DCHECK(!g_utility_zygote);
   g_utility_zygote = CreateZygote();
 }
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 bool UtilityProcessHostImpl::StartProcess() {
   if (started_)
