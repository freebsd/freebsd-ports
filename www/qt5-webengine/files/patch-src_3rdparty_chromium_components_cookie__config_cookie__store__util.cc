--- src/3rdparty/chromium/components/cookie_config/cookie_store_util.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/components/cookie_config/cookie_store_util.cc
@@ -11,7 +11,7 @@ namespace cookie_config {
 
 namespace cookie_config {
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 namespace {
 
@@ -64,12 +64,12 @@ net::CookieCryptoDelegate* GetCookieCryptoDelegate() {
 net::CookieCryptoDelegate* GetCookieCryptoDelegate() {
   return g_cookie_crypto_delegate.Pointer();
 }
-#else   // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#else   // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 net::CookieCryptoDelegate* GetCookieCryptoDelegate() {
   return NULL;
 }
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 }  // namespace cookie_config
