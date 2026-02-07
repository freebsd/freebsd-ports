--- src/3rdparty/chromium/components/cookie_config/cookie_store_util.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/cookie_config/cookie_store_util.cc
@@ -12,7 +12,7 @@ namespace cookie_config {
 namespace cookie_config {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
