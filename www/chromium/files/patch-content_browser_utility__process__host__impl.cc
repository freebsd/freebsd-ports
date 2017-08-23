--- content/browser/utility_process_host_impl.cc.orig	2017-07-25 21:04:55.000000000 +0200
+++ content/browser/utility_process_host_impl.cc	2017-08-02 01:11:47.902348000 +0200
@@ -44,9 +44,9 @@
 #include "services/service_manager/public/cpp/interface_provider.h"
 #include "ui/base/ui_base_switches.h"
 
-#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 #include "content/public/browser/zygote_handle_linux.h"
-#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX)
+#endif  // defined(OS_POSIX) && !defined(OS_ANDROID) && !defined(OS_MACOSX) && !defined(OS_BSD)
 
 #if defined(OS_WIN)
 #include "sandbox/win/src/sandbox_policy.h"
@@ -68,10 +68,10 @@
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
 
@@ -100,13 +100,13 @@
 
 #elif defined(OS_POSIX)
 
-#if !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle GetZygote() override {
     if (no_sandbox_ || !exposed_dir_.empty())
       return nullptr;
     return GetGenericZygote();
   }
-#endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#endif  // !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   base::EnvironmentMap GetEnvironment() override { return env_; }
 #endif  // OS_WIN
 
@@ -121,9 +121,9 @@
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
 
