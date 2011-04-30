--- third_party/libjingle/source/talk/base/nethelpers.cc.orig	2011-04-19 21:39:18.195038614 +0300
+++ third_party/libjingle/source/talk/base/nethelpers.cc	2011-04-19 21:39:48.358036984 +0300
@@ -32,7 +32,7 @@
 
 namespace talk_base {
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(OS_FREEBSD)
 static const size_t kInitHostentLen = 1024;
 static const size_t kMaxHostentLen = kInitHostentLen * 8;
 #endif
@@ -121,7 +121,7 @@
   result->h_addr_list[num_addrs] = NULL;
 
   *herrno = 0;
-#elif defined(LINUX) || defined(ANDROID)
+#elif defined(LINUX) || defined(ANDROID) || defined(OS_FREEBSD)
   // gethostbyname() is not thread safe, so we need to call gethostbyname_r()
   // which is a reentrant version of gethostbyname().
   ASSERT(kInitHostentLen > sizeof(hostent));
