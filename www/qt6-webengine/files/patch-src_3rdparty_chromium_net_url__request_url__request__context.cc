--- src/3rdparty/chromium/net/url_request/url_request_context.cc.orig	2023-01-11 09:17:16 UTC
+++ src/3rdparty/chromium/net/url_request/url_request_context.cc
@@ -109,7 +109,7 @@ const HttpNetworkSessionContext* URLRequestContext::Ge
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 std::unique_ptr<URLRequest> URLRequestContext::CreateRequest(
     const GURL& url,
     RequestPriority priority,
