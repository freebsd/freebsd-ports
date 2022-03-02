--- net/url_request/url_request_context.h.orig	2022-02-28 16:54:41 UTC
+++ net/url_request/url_request_context.h
@@ -82,7 +82,7 @@ class NET_EXPORT URLRequestContext {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
