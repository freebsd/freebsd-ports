--- content/public/browser/service_process_host.cc.orig	2024-11-14 07:57:23 UTC
+++ content/public/browser/service_process_host.cc
@@ -71,7 +71,7 @@ ServiceProcessHost::Options::WithPreloadedLibraries(
 ServiceProcessHost::Options& ServiceProcessHost::Options::WithGpuClient(
     base::PassKey<ServiceProcessHostGpuClient> passkey) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   allow_gpu_client = true;
 #endif
   return *this;
