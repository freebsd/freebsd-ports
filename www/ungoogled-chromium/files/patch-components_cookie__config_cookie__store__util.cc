--- components/cookie_config/cookie_store_util.cc.orig	2025-12-06 13:30:52 UTC
+++ components/cookie_config/cookie_store_util.cc
@@ -16,7 +16,7 @@
 namespace cookie_config {
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace {
 
 void OnOsCryptReadyOnUi(
