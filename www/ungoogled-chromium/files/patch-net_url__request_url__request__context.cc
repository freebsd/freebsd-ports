--- net/url_request/url_request_context.cc.orig	2025-01-25 09:34:31 UTC
+++ net/url_request/url_request_context.cc
@@ -122,7 +122,7 @@ const HttpNetworkSessionContext* URLRequestContext::Ge
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
