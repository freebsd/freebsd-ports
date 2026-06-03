--- _cffi_build/secp256k1.h.orig	2026-01-28 09:10:51 UTC
+++ _cffi_build/secp256k1.h
@@ -133,7 +133,7 @@ int secp256k1_ec_pubkey_create(
     const unsigned char *seckey
 );
 
-int secp256k1_ec_privkey_tweak_add(
+int secp256k1_ec_seckey_tweak_add(
     const secp256k1_context* ctx,
     unsigned char *seckey,
     const unsigned char *tweak
@@ -145,7 +145,7 @@ int secp256k1_ec_pubkey_tweak_add(
     const unsigned char *tweak
 );
 
-int secp256k1_ec_privkey_tweak_mul(
+int secp256k1_ec_seckey_tweak_mul(
     const secp256k1_context* ctx,
     unsigned char *seckey,
     const unsigned char *tweak
