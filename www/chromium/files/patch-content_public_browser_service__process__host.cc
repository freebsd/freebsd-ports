--- content/public/browser/service_process_host.cc.orig	2024-04-19 13:02:56 UTC
+++ content/public/browser/service_process_host.cc
@@ -76,7 +76,7 @@ ServiceProcessHost::Options& ServiceProcessHost::Optio
 
 ServiceProcessHost::Options& ServiceProcessHost::Options::WithGpuClient(
     base::PassKey<ServiceProcessHostGpuClient> passkey) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
   allow_gpu_client = true;
 #endif
   return *this;
