--- src/archiver.cpp.orig	2016-05-10 20:45:50 UTC
+++ src/archiver.cpp
@@ -97,7 +97,8 @@ Archiver::exportAccounts(std::vector<std
     }
 
     // Encrypt using provided password
-    auto encrypted = dht::crypto::aesEncrypt(compressed, password);
+    dht::Blob blob; for (auto c : password) blob.push_back(c);
+    auto encrypted = dht::crypto::aesEncrypt(compressed, blob);
 
     // Write
     try {
@@ -151,7 +152,8 @@ Archiver::importAccounts(std::string arc
 
     // Decrypt
     try {
-        file = dht::crypto::aesDecrypt(file, password);
+        dht::Blob blob; for (auto c : password) blob.push_back(c);
+        file = dht::crypto::aesDecrypt(file, blob);
     } catch (const std::exception& ex) {
         RING_ERR("Decryption failed: %s", ex.what());
         return EPERM;
