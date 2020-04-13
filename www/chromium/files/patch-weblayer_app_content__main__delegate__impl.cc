--- weblayer/app/content_main_delegate_impl.cc.orig	2020-03-17 10:35:42 UTC
+++ weblayer/app/content_main_delegate_impl.cc
@@ -146,7 +146,7 @@ bool ContentMainDelegateImpl::BasicStartupComplete(int
 }
 
 void ContentMainDelegateImpl::PreSandboxStartup() {
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
