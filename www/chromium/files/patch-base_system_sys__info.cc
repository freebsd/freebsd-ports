--- base/system/sys_info.cc.orig	2020-06-25 12:19:57 UTC
+++ base/system/sys_info.cc
@@ -102,7 +102,7 @@ void SysInfo::GetHardwareInfo(base::OnceCallback<void(
 #elif defined(OS_ANDROID) || defined(OS_MACOSX)
   base::ThreadPool::PostTaskAndReplyWithResult(
       FROM_HERE, {}, base::BindOnce(&GetHardwareInfoSync), std::move(callback));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   base::ThreadPool::PostTaskAndReplyWithResult(
       FROM_HERE, {base::MayBlock()}, base::BindOnce(&GetHardwareInfoSync),
       std::move(callback));
