--- chrome/renderer/pepper/pepper_flash_font_file_host.h.orig	2014-10-02 17:18:55 UTC
+++ chrome/renderer/pepper/pepper_flash_font_file_host.h
@@ -10,7 +10,7 @@
 #include "ppapi/c/private/pp_private_font_charset.h"
 #include "ppapi/host/resource_host.h"
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/files/scoped_file.h"
 #endif
 
@@ -45,7 +45,7 @@
   // Non-owning pointer.
   content::RendererPpapiHost* renderer_ppapi_host_;
 
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::ScopedFD fd_;
 #endif
 
