--- skia/ext/SkThread_chrome.cc.orig	2012-08-12 21:13:49.131615957 +0300
+++ skia/ext/SkThread_chrome.cc	2012-08-12 21:14:44.603258675 +0300
@@ -51,7 +51,7 @@
         }
 
         int32_t before;
-        before = base::subtle::Aquire_CompareAndSwap(addr, value, value + 1);
+        before = base::subtle::Acquire_CompareAndSwap(addr, value, value + 1);
 
         if (before == value) {
             return value;
