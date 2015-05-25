--- chrome/browser/net/cookie_store_util.cc.orig	2015-04-14 18:31:21.000000000 -0400
+++ chrome/browser/net/cookie_store_util.cc	2015-04-28 10:11:34.004175000 -0400
@@ -120,7 +120,7 @@
       new ChromeCookieMonsterDelegate(profile));
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
