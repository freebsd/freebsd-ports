--- weblayer/app/content_main_delegate_impl.cc.orig	2021-12-31 00:58:32 UTC
+++ weblayer/app/content_main_delegate_impl.cc
@@ -252,8 +252,8 @@ ContentMainDelegateImpl::CreateVariationsIdsProvider()
 void ContentMainDelegateImpl::PreSandboxStartup() {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(ARCH_CPU_ARM_FAMILY) &&              \
-    (defined(OS_ANDROID) || defined(OS_LINUX) || \
+#if defined(ARCH_CPU_ARM_FAMILY) &&                              \
+    (defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD) \
      BUILDFLAG(IS_CHROMEOS_LACROS))
   // Create an instance of the CPU class to parse /proc/cpuinfo and cache
   // cpu_brand info.
