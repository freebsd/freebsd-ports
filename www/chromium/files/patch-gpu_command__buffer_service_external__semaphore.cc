--- gpu/command_buffer/service/external_semaphore.cc.orig	2021-07-19 18:45:17 UTC
+++ gpu/command_buffer/service/external_semaphore.cc
@@ -27,7 +27,7 @@ GLuint ImportSemaphoreHandleToGLSemaphore(SemaphoreHan
   if (!handle.is_valid())
     return 0;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
   if (handle.vk_handle_type() !=
       VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT) {
     DLOG(ERROR) << "Importing semaphore handle of unexpected type:"
