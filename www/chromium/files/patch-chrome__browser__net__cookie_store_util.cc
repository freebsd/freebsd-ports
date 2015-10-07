--- chrome/browser/net/cookie_store_util.cc.orig	2015-07-21 21:42:54.358730000 -0400
+++ chrome/browser/net/cookie_store_util.cc	2015-07-21 21:43:07.938330000 -0400
@@ -85,7 +85,7 @@
       new ChromeCookieMonsterDelegate(profile));
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
