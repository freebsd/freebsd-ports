--- chrome/browser/profiles/profile_impl_io_data.cc.orig	2017-01-26 00:49:08 UTC
+++ chrome/browser/profiles/profile_impl_io_data.cc
@@ -104,7 +104,7 @@ net::BackendType ChooseCacheBackendType(
   }
 #endif  // #if !defined(OS_ANDROID)
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return net::CACHE_BACKEND_SIMPLE;
 #else
   return net::CACHE_BACKEND_BLOCKFILE;
