--- net/url_request/url_request_context.cc.orig	2020-03-16 18:39:54 UTC
+++ net/url_request/url_request_context.cc
@@ -89,7 +89,7 @@ const HttpNetworkSession::Context* URLRequestContext::
   return &network_session->context();
 }
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
