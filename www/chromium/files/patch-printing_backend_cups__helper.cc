--- printing/backend/cups_helper.cc.orig	2025-09-06 10:01:20 UTC
+++ printing/backend/cups_helper.cc
@@ -13,7 +13,7 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <cups/ppd.h>
 #include <stddef.h>
 #include <stdio.h>
@@ -43,11 +43,11 @@
 #include "url/gurl.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 using base::EqualsCaseInsensitiveASCII;
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -60,7 +60,7 @@ namespace {
 // able to start and respond on all systems within this duration.
 constexpr base::TimeDelta kCupsTimeout = base::Seconds(5);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // CUPS default max copies value (parsed from kCupsMaxCopies PPD attribute).
 constexpr int32_t kDefaultMaxCopies = 9999;
 constexpr char kCupsMaxCopies[] = "cupsMaxCopies";
@@ -766,7 +766,7 @@ const int kDefaultIPPServerPort = 631;
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Helper wrapper around http_t structure, with connection and cleanup
 // functionality.
 HttpConnectionCUPS::HttpConnectionCUPS(const GURL& print_server_url,
@@ -971,7 +971,7 @@ ScopedHttpPtr HttpConnect2(const char* host,
                            int blocking,
                            int msec,
                            int* cancel) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ScopedHttpPtr http;
   if (httpConnect2) {
     http.reset(httpConnect2(host, port,
