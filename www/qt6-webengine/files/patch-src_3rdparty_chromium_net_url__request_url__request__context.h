--- src/3rdparty/chromium/net/url_request/url_request_context.h.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/net/url_request/url_request_context.h
@@ -86,7 +86,7 @@ class NET_EXPORT URLRequestContext final {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
