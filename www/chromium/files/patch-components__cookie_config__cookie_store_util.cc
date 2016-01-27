--- ./components/cookie_config/cookie_store_util.cc.orig	2016-01-21 14:31:28.175486313 +0100
+++ ./components/cookie_config/cookie_store_util.cc	2016-01-21 14:32:42.351481630 +0100
@@ -10,7 +10,7 @@
 
 namespace cookie_config {
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
@@ -62,10 +62,10 @@
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
