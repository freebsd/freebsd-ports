--- src/3rdparty/chromium/net/url_request/url_fetcher.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/net/url_request/url_fetcher.cc
@@ -21,7 +21,7 @@ void URLFetcher::SetIgnoreCertificateRequests(bool ign
   URLFetcherImpl::SetIgnoreCertificateRequests(ignored);
 }
 
-#if (!defined(OS_WIN) && !defined(OS_LINUX)) || defined(OS_CHROMEOS)
+#if (!defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 // static
 std::unique_ptr<URLFetcher> URLFetcher::Create(
     const GURL& url,
