--- chrome/renderer/pepper/pepper_flash_font_file_host.cc.orig	2017-04-19 19:06:31 UTC
+++ chrome/renderer/pepper/pepper_flash_font_file_host.cc
@@ -14,7 +14,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/proxy/serialized_structs.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/child/child_process_sandbox_support_linux.h"
 #include "content/public/common/common_sandbox_support_linux.h"
 #elif defined(OS_WIN)
@@ -28,7 +28,7 @@ PepperFlashFontFileHost::PepperFlashFont
     const ppapi::proxy::SerializedFontDescription& description,
     PP_PrivateFontCharset charset)
     : ResourceHost(host->GetPpapiHost(), instance, resource) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   fd_.reset(content::MatchFontWithFallback(
       description.face,
       description.weight >= PP_BROWSERFONT_TRUSTED_WEIGHT_BOLD,
@@ -45,7 +45,7 @@ PepperFlashFontFileHost::PepperFlashFont
   sk_sp<SkFontMgr> font_mgr(SkFontMgr::RefDefault());
   typeface_ = sk_sp<SkTypeface>(
       font_mgr->matchFamilyStyle(description.face.c_str(), style));
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 PepperFlashFontFileHost::~PepperFlashFontFileHost() {}
@@ -64,7 +64,7 @@ bool PepperFlashFontFileHost::GetFontDat
                                           void* buffer,
                                           size_t* length) {
   bool result = false;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int fd = fd_.get();
   if (fd != -1)
     result = content::GetFontTable(fd, table, 0 /* offset */,
