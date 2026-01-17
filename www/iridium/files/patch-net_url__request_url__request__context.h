--- net/url_request/url_request_context.h.orig	2026-01-16 14:21:21 UTC
+++ net/url_request/url_request_context.h
@@ -89,7 +89,7 @@ class NET_EXPORT URLRequestContext final {
   // session.
   const HttpNetworkSessionContext* GetNetworkSessionContext() const;
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
