--- chrome/browser/net/cookie_store_util.cc.orig	2015-10-14 19:42:28.950909000 +0200
+++ chrome/browser/net/cookie_store_util.cc	2015-10-14 19:43:32.447326000 +0200
@@ -15,7 +15,7 @@
 
 namespace chrome_browser_net {
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
@@ -67,10 +67,10 @@
 net::CookieCryptoDelegate* GetCookieCryptoDelegate() {
   return g_cookie_crypto_delegate.Pointer();
 }
-#else  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#else  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 net::CookieCryptoDelegate* GetCookieCryptoDelegate() {
   return NULL;
 }
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace chrome_browser_net
