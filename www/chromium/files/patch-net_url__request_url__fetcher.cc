--- net/url_request/url_fetcher.cc.orig	2022-02-28 16:54:41 UTC
+++ net/url_request/url_fetcher.cc
@@ -26,7 +26,7 @@ void URLFetcher::SetIgnoreCertificateRequests(bool ign
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if !BUILDFLAG(IS_WIN) && \
-    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 // static
 std::unique_ptr<URLFetcher> URLFetcher::Create(
     const GURL& url,
