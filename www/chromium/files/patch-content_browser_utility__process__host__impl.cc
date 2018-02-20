--- content/browser/utility_process_host_impl.cc.orig	2017-12-15 02:04:17.000000000 +0100
+++ content/browser/utility_process_host_impl.cc	2017-12-24 13:10:10.983464000 +0100
@@ -35,9 +35,9 @@
 #include "services/service_manager/sandbox/sandbox_type.h"
 #include "ui/base/ui_base_switches.h"
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/browser/zygote_handle_linux.h"
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include "sandbox/win/src/sandbox_policy.h"
@@ -96,7 +96,7 @@
 
 #elif defined(OS_POSIX)
 
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   ZygoteHandle GetZygote() override {
     if (service_manager::IsUnsandboxedSandboxType(sandbox_type_) ||
         !exposed_dir_.empty()) {
@@ -104,7 +104,7 @@
     }
     return GetGenericZygote();
   }
-#endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA)
+#endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_FUCHSIA) && !defined(OS_BSD)
   base::EnvironmentMap GetEnvironment() override { return env_; }
 #endif  // OS_WIN
 
