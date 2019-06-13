--- gpu/command_buffer/service/external_vk_image_gl_representation.cc.orig	2019-06-04 18:55:24 UTC
+++ gpu/command_buffer/service/external_vk_image_gl_representation.cc
@@ -128,7 +128,7 @@ GLuint ExternalVkImageGlRepresentation::ImportVkSemaph
 #if defined(OS_FUCHSIA)
   NOTIMPLEMENTED_LOG_ONCE();
   return 0;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (handle.vk_handle_type() !=
       VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT) {
     DLOG(ERROR) << "Importing semaphore handle of unexpected type:"
@@ -143,7 +143,7 @@ GLuint ExternalVkImageGlRepresentation::ImportVkSemaph
                                 fd.release());
 
   return gl_semaphore;
-#else  // !defined(OS_FUCHSIA) && !defined(OS_LINUX)
+#else  // !defined(OS_FUCHSIA) && !defined(OS_LINUX) && !defined(OS_BSD)
 #error Unsupported OS
 #endif
 }
