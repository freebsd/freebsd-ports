--- net/url_request/url_fetcher.cc.orig	2021-04-14 18:41:07 UTC
+++ net/url_request/url_fetcher.cc
@@ -24,7 +24,7 @@ void URLFetcher::SetIgnoreCertificateRequests(bool ign
 
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if !defined(OS_WIN) && !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !defined(OS_WIN) && !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 // static
 std::unique_ptr<URLFetcher> URLFetcher::Create(
     const GURL& url,
