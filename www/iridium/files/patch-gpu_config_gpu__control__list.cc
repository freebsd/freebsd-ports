--- gpu/config/gpu_control_list.cc.orig	2023-11-22 14:00:11 UTC
+++ gpu/config/gpu_control_list.cc
@@ -276,7 +276,7 @@ bool GpuControlList::More::GLVersionInfoMismatch(
 GpuControlList::GLType GpuControlList::More::GetDefaultGLType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return kGLTypeGL;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kGLTypeGL;
 #elif BUILDFLAG(IS_MAC)
   return kGLTypeGL;
@@ -820,7 +820,7 @@ GpuControlList::OsType GpuControlList::GetOsType() {
   return kOsAndroid;
 #elif BUILDFLAG(IS_FUCHSIA)
   return kOsFuchsia;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_MAC)
   return kOsMacosx;
