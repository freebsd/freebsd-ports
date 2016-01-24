--- chrome/renderer/pepper/pepper_flash_font_file_host.cc.orig	2016-01-21 15:55:11.104140125 +0100
+++ chrome/renderer/pepper/pepper_flash_font_file_host.cc	2016-01-21 15:57:35.816130405 +0100
@@ -14,7 +14,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/proxy/serialized_structs.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "content/public/common/child_process_sandbox_support_linux.h"
 #elif defined(OS_WIN)
 #include "third_party/skia/include/ports/SkFontMgr.h"
@@ -27,7 +27,7 @@
     const ppapi::proxy::SerializedFontDescription& description,
     PP_PrivateFontCharset charset)
     : ResourceHost(host->GetPpapiHost(), instance, resource) {
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   fd_.reset(content::MatchFontWithFallback(
       description.face,
       description.weight >= PP_BROWSERFONT_TRUSTED_WEIGHT_BOLD,
@@ -44,7 +44,7 @@
   skia::RefPtr<SkFontMgr> font_mgr = skia::AdoptRef(SkFontMgr::RefDefault());
   typeface_ = skia::AdoptRef(
       font_mgr->matchFamilyStyle(description.face.c_str(), style));
-#endif  // defined(OS_LINUX) || defined(OS_OPENBSD)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
 }
 
 PepperFlashFontFileHost::~PepperFlashFontFileHost() {}
@@ -63,7 +63,7 @@
                                           void* buffer,
                                           size_t* length) {
   bool result = false;
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int fd = fd_.get();
   if (fd != -1)
     result = content::GetFontTable(fd, table, 0 /* offset */,
