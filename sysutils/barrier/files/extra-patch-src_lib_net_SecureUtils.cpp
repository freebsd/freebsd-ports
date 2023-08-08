--- src/lib/net/SecureUtils.cpp.orig	2023-07-21 23:37:03 UTC
+++ src/lib/net/SecureUtils.cpp
@@ -160,17 +160,11 @@ void generate_pem_self_signed_cert(const std::string& 
 {
     auto expiration_days = 365;
 
-    auto* private_key = EVP_PKEY_new();
+    auto* private_key = EVP_RSA_gen(2048);
     if (!private_key) {
         throw std::runtime_error("Could not allocate private key for certificate");
     }
     auto private_key_free = finally([private_key](){ EVP_PKEY_free(private_key); });
-
-    auto* rsa = RSA_generate_key(2048, RSA_F4, nullptr, nullptr);
-    if (!rsa) {
-        throw std::runtime_error("Failed to generate RSA key");
-    }
-    EVP_PKEY_assign_RSA(private_key, rsa);
 
     auto* cert = X509_new();
     if (!cert) {
