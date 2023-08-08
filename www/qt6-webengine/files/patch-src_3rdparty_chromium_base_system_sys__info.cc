--- src/3rdparty/chromium/base/system/sys_info.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/base/system/sys_info.cc
@@ -101,7 +101,7 @@ void SysInfo::GetHardwareInfo(base::OnceCallback<void(
 #endif
 
 void SysInfo::GetHardwareInfo(base::OnceCallback<void(HardwareInfo)> callback) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   constexpr base::TaskTraits kTraits = {base::MayBlock()};
 #else
   constexpr base::TaskTraits kTraits = {};
