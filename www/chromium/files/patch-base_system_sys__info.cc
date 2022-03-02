--- base/system/sys_info.cc.orig	2022-02-28 16:54:41 UTC
+++ base/system/sys_info.cc
@@ -100,7 +100,7 @@ void SysInfo::GetHardwareInfo(base::OnceCallback<void(
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_APPLE)
   base::ThreadPool::PostTaskAndReplyWithResult(
       FROM_HERE, {}, base::BindOnce(&GetHardwareInfoSync), std::move(callback));
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::ThreadPool::PostTaskAndReplyWithResult(
       FROM_HERE, {base::MayBlock()}, base::BindOnce(&GetHardwareInfoSync),
       std::move(callback));
