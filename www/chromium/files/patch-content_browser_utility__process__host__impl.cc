--- content/browser/utility_process_host_impl.cc.orig	2016-05-11 19:02:21 UTC
+++ content/browser/utility_process_host_impl.cc
@@ -37,7 +37,7 @@
 #include "ipc/ipc_switches.h"
 #include "ui/base/ui_base_switches.h"
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/browser/zygote_handle_linux.h"
 #endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
 
@@ -48,7 +48,7 @@
 
 namespace content {
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 namespace {
 ZygoteHandle g_utility_zygote;
 }  // namespace
@@ -68,7 +68,7 @@ class UtilitySandboxedProcessLauncherDel
         launch_elevated_(launch_elevated)
 #elif defined(OS_POSIX)
         env_(env),
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         no_sandbox_(no_sandbox),
 #endif  // !defined(OS_MACOSX)  && !defined(OS_ANDROID)
         ipc_fd_(host->TakeClientFileDescriptor())
@@ -100,7 +100,7 @@ class UtilitySandboxedProcessLauncherDel
 
 #elif defined(OS_POSIX)
 
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     if (no_sandbox_ || !exposed_dir_.empty())
       return nullptr;
@@ -122,7 +122,7 @@ class UtilitySandboxedProcessLauncherDel
   bool launch_elevated_;
 #elif defined(OS_POSIX)
   base::EnvironmentMap env_;
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   bool no_sandbox_;
 #endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID)
   base::ScopedFD ipc_fd_;
@@ -238,7 +238,7 @@ void UtilityProcessHostImpl::SetName(con
   name_ = name;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void UtilityProcessHostImpl::EarlyZygoteLaunch() {
   DCHECK(!g_utility_zygote);
