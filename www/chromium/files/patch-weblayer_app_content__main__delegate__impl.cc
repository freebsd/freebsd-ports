--- weblayer/app/content_main_delegate_impl.cc.orig	2021-03-12 23:57:49 UTC
+++ weblayer/app/content_main_delegate_impl.cc
@@ -218,7 +218,7 @@ bool ContentMainDelegateImpl::ShouldCreateFeatureList(
 }
 
 void ContentMainDelegateImpl::PreSandboxStartup() {
-#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX))
+#if defined(ARCH_CPU_ARM_FAMILY) && (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
   base::CPU cpu_info;
