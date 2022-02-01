--- base/system/sys_info.cc.orig	2021-12-14 11:44:55 UTC
+++ base/system/sys_info.cc
@@ -92,7 +92,7 @@ void SysInfo::GetHardwareInfo(base::OnceCallback<void(
 #if defined(OS_WIN) || defined(OS_ANDROID) || defined(OS_APPLE)
   base::ThreadPool::PostTaskAndReplyWithResult(
       FROM_HERE, {}, base::BindOnce(&GetHardwareInfoSync), std::move(callback));
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   base::ThreadPool::PostTaskAndReplyWithResult(
       FROM_HERE, {base::MayBlock()}, base::BindOnce(&GetHardwareInfoSync),
       std::move(callback));
