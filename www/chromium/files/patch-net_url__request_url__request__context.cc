--- net/url_request/url_request_context.cc.orig	2020-07-07 21:57:40 UTC
+++ net/url_request/url_request_context.cc
@@ -90,7 +90,7 @@ const HttpNetworkSession::Context* URLRequestContext::
   return &network_session->context();
 }
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
