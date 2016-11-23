--- content/browser/utility_process_host_impl.cc.orig	2016-07-20 22:03:24.000000000 +0300
+++ content/browser/utility_process_host_impl.cc	2016-08-18 02:26:27.996136000 +0300
@@ -38,7 +38,7 @@
 #include "ipc/ipc_switches.h"
 #include "ui/base/ui_base_switches.h"
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/browser/zygote_handle_linux.h"
 #endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
 
@@ -49,7 +49,7 @@
 
 namespace content {
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 namespace {
 ZygoteHandle g_utility_zygote;
 }  // namespace
@@ -69,7 +69,7 @@
         launch_elevated_(launch_elevated)
 #elif defined(OS_POSIX)
         env_(env),
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
         no_sandbox_(no_sandbox),
 #endif  // !defined(OS_MACOSX)  && !defined(OS_ANDROID)
         ipc_fd_(host->TakeClientFileDescriptor())
@@ -101,7 +101,7 @@
 
 #elif defined(OS_POSIX)
 
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle* GetZygote() override {
     if (no_sandbox_ || !exposed_dir_.empty())
       return nullptr;
@@ -123,7 +123,7 @@
   bool launch_elevated_;
 #elif defined(OS_POSIX)
   base::EnvironmentMap env_;
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   bool no_sandbox_;
 #endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID)
   base::ScopedFD ipc_fd_;
@@ -151,7 +151,7 @@
       is_batch_mode_(false),
       no_sandbox_(false),
       run_elevated_(false),
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       child_flags_(ChildProcessHost::CHILD_ALLOW_SELF),
 #else
       child_flags_(ChildProcessHost::CHILD_NORMAL),
@@ -232,7 +232,7 @@
   name_ = name;
 }
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 // static
 void UtilityProcessHostImpl::EarlyZygoteLaunch() {
   DCHECK(!g_utility_zygote);
