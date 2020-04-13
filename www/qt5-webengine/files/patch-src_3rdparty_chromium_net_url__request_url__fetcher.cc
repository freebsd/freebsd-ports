--- src/3rdparty/chromium/net/url_request/url_fetcher.cc.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/net/url_request/url_fetcher.cc
@@ -11,7 +11,7 @@ namespace net {
 
 URLFetcher::~URLFetcher() = default;
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 // static
 std::unique_ptr<URLFetcher> URLFetcher::Create(
     const GURL& url,
