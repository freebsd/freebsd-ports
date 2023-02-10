--- src/3rdparty/chromium/net/url_request/url_fetcher.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/net/url_request/url_fetcher.h
@@ -344,7 +344,7 @@ class NET_EXPORT URLFetcher {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if (!BUILDFLAG(IS_WIN) &&                                       \
-     !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))) || \
+     !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))) || \
     BUILDFLAG(IS_CHROMEOS)
   // |url| is the URL to send the request to. It must be valid.
   // |request_type| is the type of request to make.
