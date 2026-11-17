--- src/chrome/browser/ui/webui/sanitized_image/sanitized_image_source.h.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/webui/sanitized_image/sanitized_image_source.h
@@ -124,7 +124,7 @@ class SanitizedImageSource : public cont
     ~RequestAttributes();
 
     GURL image_url = GURL();
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     bool static_encode = true;
 #else
     bool static_encode = false;
