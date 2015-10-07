--- chrome/renderer/pepper/pepper_flash_font_file_host.cc.orig	2015-08-22 15:01:53.000000000 -0400
+++ chrome/renderer/pepper/pepper_flash_font_file_host.cc	2015-09-03 10:01:52.619879000 -0400
@@ -13,7 +13,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/proxy/serialized_structs.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/common/child_process_sandbox_support_linux.h"
 #endif
 
@@ -24,14 +24,14 @@
     const ppapi::proxy::SerializedFontDescription& description,
     PP_PrivateFontCharset charset)
     : ResourceHost(host->GetPpapiHost(), instance, resource) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   fd_.reset(content::MatchFontWithFallback(
       description.face,
       description.weight >= PP_BROWSERFONT_TRUSTED_WEIGHT_BOLD,
       description.italic,
       charset,
       PP_BROWSERFONT_TRUSTED_FAMILY_DEFAULT));
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 PepperFlashFontFileHost::~PepperFlashFontFileHost() {}
@@ -51,7 +51,7 @@
     uint32_t table) {
   std::string contents;
   int32_t result = PP_ERROR_FAILED;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int fd = fd_.get();
   if (fd != -1) {
     size_t length = 0;
@@ -67,7 +67,7 @@
       }
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   context->reply_msg = PpapiPluginMsg_FlashFontFile_GetFontTableReply(contents);
   return result;
