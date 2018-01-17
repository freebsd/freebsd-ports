--- src/3rdparty/chromium/components/cookie_config/cookie_store_util.cc.orig	2017-01-26 00:49:11 UTC
+++ src/3rdparty/chromium/components/cookie_config/cookie_store_util.cc
@@ -11,7 +11,7 @@
 
 namespace cookie_config {
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
@@ -63,10 +63,10 @@ base::LazyInstance<CookieOSCryptoDelegat
 net::CookieCryptoDelegate* GetCookieCryptoDelegate() {
   return g_cookie_crypto_delegate.Pointer();
 }
-#else   // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#else   // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 net::CookieCryptoDelegate* GetCookieCryptoDelegate() {
   return NULL;
 }
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 }  // namespace cookie_config
