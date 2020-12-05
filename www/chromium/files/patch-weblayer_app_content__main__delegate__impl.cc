--- weblayer/app/content_main_delegate_impl.cc.orig	2020-11-13 06:37:06 UTC
+++ weblayer/app/content_main_delegate_impl.cc
@@ -225,7 +225,7 @@ bool ContentMainDelegateImpl::ShouldCreateFeatureList(
 
 void ContentMainDelegateImpl::PreSandboxStartup() {
 #if defined(ARCH_CPU_ARM_FAMILY) && \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
