--- gpu/config/gpu_control_list.cc.orig	2025-02-20 09:59:21 UTC
+++ gpu/config/gpu_control_list.cc
@@ -831,7 +831,7 @@ GpuControlList::OsType GpuControlList::GetOsType() {
   return kOsAndroid;
 #elif BUILDFLAG(IS_FUCHSIA)
   return kOsFuchsia;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_MAC)
   return kOsMacosx;
