--- src/gpu/config/gpu_control_list.cc.orig	2026-10-18 18:43:23 UTC
+++ src/gpu/config/gpu_control_list.cc
@@ -837,7 +837,7 @@ GpuControlList::OsType GpuControlList::G
   return kOsAndroid;
 #elif BUILDFLAG(IS_FUCHSIA)
   return kOsFuchsia;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_MAC)
   return kOsMacosx;
