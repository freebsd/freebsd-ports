--- talk/base/ssladapter.cc.orig	Wed Feb 22 00:28:05 2006
+++ talk/base/ssladapter.cc	Wed Feb 22 00:29:01 2006
@@ -99,7 +99,7 @@
 }
 
 static unsigned long id_function() {
-  return static_cast<unsigned long>(THREAD_ID);
+  return reinterpret_cast<unsigned long>(THREAD_ID);
 }
 
 struct CRYPTO_dynlock_value {
