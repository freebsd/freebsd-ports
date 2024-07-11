--- content/public/browser/content_browser_client.cc.orig	2024-06-22 08:49:42 UTC
+++ content/public/browser/content_browser_client.cc
@@ -1303,7 +1303,7 @@ bool ContentBrowserClient::ShouldRunOutOfProcessSystem
 // that can be adequately sandboxed.
 // Currently Android's network service will not run out of process or sandboxed,
 // so OutOfProcessSystemDnsResolution is not currently enabled on Android.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
