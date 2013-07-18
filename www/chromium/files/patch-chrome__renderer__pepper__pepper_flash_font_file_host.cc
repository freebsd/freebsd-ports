--- chrome/renderer/pepper/pepper_flash_font_file_host.cc.orig	2013-07-15 20:44:54.000000000 +0300
+++ chrome/renderer/pepper/pepper_flash_font_file_host.cc	2013-07-15 20:45:49.000000000 +0300
@@ -13,7 +13,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/proxy/serialized_structs.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/common/child_process_sandbox_support_linux.h"
 #endif
 
@@ -28,12 +28,12 @@
     : ResourceHost(host->GetPpapiHost(), instance, resource),
       renderer_ppapi_host_(host),
       fd_(-1) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   fd_ = content::MatchFontWithFallback(
       description.face.c_str(), description.weight >=
           PP_BROWSERFONT_TRUSTED_WEIGHT_BOLD,
       description.italic, charset);
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 PepperFlashFontFileHost::~PepperFlashFontFileHost() {
@@ -54,7 +54,7 @@
     uint32_t table) {
   std::string contents;
   int32_t result = PP_ERROR_FAILED;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (fd_ != -1) {
     size_t length = 0;
     if (content::GetFontTable(fd_, table, 0 /* offset */, NULL, &length)) {
@@ -69,7 +69,7 @@
       }
     }
   }
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 
   context->reply_msg = PpapiPluginMsg_FlashFontFile_GetFontTableReply(contents);
   return result;
