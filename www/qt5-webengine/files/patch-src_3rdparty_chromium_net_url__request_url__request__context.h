--- src/3rdparty/chromium/net/url_request/url_request_context.h.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/net/url_request/url_request_context.h
@@ -90,7 +90,7 @@ class NET_EXPORT URLRequestContext
   // session.
   const HttpNetworkSession::Context* GetNetworkSessionContext() const;
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
   // This function should not be used in Chromium, please use the version with
   // NetworkTrafficAnnotationTag in the future.
   //
