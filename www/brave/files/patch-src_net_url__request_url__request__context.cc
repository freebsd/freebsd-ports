--- src/net/url_request/url_request_context.cc.orig	2026-10-18 18:43:23 UTC
+++ src/net/url_request/url_request_context.cc
@@ -130,7 +130,7 @@ const HttpNetworkSessionContext* URLRequ
   return &network_session->context();
 }
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
