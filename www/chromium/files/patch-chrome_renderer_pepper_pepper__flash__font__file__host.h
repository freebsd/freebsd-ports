--- chrome/renderer/pepper/pepper_flash_font_file_host.h.orig	2016-05-11 19:02:17 UTC
+++ chrome/renderer/pepper/pepper_flash_font_file_host.h
@@ -14,7 +14,7 @@
 #include "ppapi/c/private/pp_private_font_charset.h"
 #include "ppapi/host/resource_host.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/scoped_file.h"
 #elif defined(OS_WIN)
 #include "skia/ext/refptr.h"
@@ -50,7 +50,7 @@ class PepperFlashFontFileHost : public p
                          uint32_t table);
   bool GetFontData(uint32_t table, void* buffer, size_t* length);
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::ScopedFD fd_;
 #elif defined(OS_WIN)
   skia::RefPtr<SkTypeface> typeface_;
