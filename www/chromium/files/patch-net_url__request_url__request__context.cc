--- net/url_request/url_request_context.cc.orig	2019-10-30 16:19:57 UTC
+++ net/url_request/url_request_context.cc
@@ -89,7 +89,7 @@ const HttpNetworkSession::Context* URLRequestContext::
   return &network_session->context();
 }
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
