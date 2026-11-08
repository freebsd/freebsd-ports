--- net/url_request/url_request_context.cc.orig	2026-09-25 15:26:43 UTC
+++ net/url_request/url_request_context.cc
@@ -130,7 +130,7 @@ const HttpNetworkSessionContext* URLRequestContext::Ge
   return &network_session->context();
 }
 
-#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
