--- src/net/HttpMessage.cpp.orig	Sat Sep 29 15:57:14 2007
+++ src/net/HttpMessage.cpp	Sat Sep 29 15:59:10 2007
@@ -3304,10 +3304,10 @@
             decodedCookie);
 #endif
         // Parse out the userId and password
-        int userPasswordSeparatorIndex = (int) strchr(decodedCookie, ':');
+        uintptr_t userPasswordSeparatorIndex = (uintptr_t) strchr(decodedCookie, ':');
         if(userPasswordSeparatorIndex)
         {
-            userPasswordSeparatorIndex -= (int) decodedCookie;
+            userPasswordSeparatorIndex -= (uintptr_t) decodedCookie;
 
             userId->append(decodedCookie, userPasswordSeparatorIndex);
             password->append(&decodedCookie[userPasswordSeparatorIndex + 1],
