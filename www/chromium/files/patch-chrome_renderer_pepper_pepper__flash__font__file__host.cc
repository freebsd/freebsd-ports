--- chrome/renderer/pepper/pepper_flash_font_file_host.cc.orig	2021-09-14 01:51:52 UTC
+++ chrome/renderer/pepper/pepper_flash_font_file_host.cc
@@ -16,7 +16,7 @@
 #include "ppapi/proxy/ppapi_messages.h"
 #include "ppapi/proxy/serialized_structs.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "components/services/font/public/cpp/font_loader.h"
 #include "pdf/font_table_linux.h"
 #elif defined(OS_WIN)
@@ -30,7 +30,7 @@ PepperFlashFontFileHost::PepperFlashFontFileHost(
     const ppapi::proxy::SerializedFontDescription& description,
     PP_PrivateFontCharset charset)
     : ResourceHost(host->GetPpapiHost(), instance, resource) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // The global SkFontConfigInterface is configured and initialized with a
   // SkFontconfigInterface compatible font_service::FontLoader in
   // RendererBlinkPlatformImpl (called from RenderThreadImpl::Init) at startup
@@ -75,7 +75,7 @@ bool PepperFlashFontFileHost::GetFontData(uint32_t tab
                                           void* buffer,
                                           size_t* length) {
   bool result = false;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (font_file_.IsValid()) {
     result =
         pdf::GetFontTable(font_file_.GetPlatformFile(), table, /*offset=*/0,
