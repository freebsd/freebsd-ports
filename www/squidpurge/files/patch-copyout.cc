--- copyout.cc.orig	2000-09-21 13:05:31 UTC
+++ copyout.cc
@@ -132,7 +132,7 @@ copy_out( size_t filesize, size_t metasi
   static const char* index = "index.html";
   
   // find hostname part after the scheme (okok, not counting port, etc.)
-  char* ptr = strstr( url, "://" );
+  const char* ptr = strstr( url, "://" );
   if ( ptr == 0 || strlen(ptr) < 4 ) return false;
 
   // create filename to store contents into
