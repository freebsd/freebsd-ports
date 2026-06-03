--- secp256k1/__init__.py.orig	2026-01-28 09:09:44 UTC
+++ secp256k1/__init__.py
@@ -319,14 +319,14 @@ class PrivateKey(ECDSA):
         Tweak the current private key by adding a 32 byte scalar
         to it and return a new raw private key composed of 32 bytes.
         """
-        return _tweak_private(self, lib.secp256k1_ec_privkey_tweak_add, scalar)
+        return _tweak_private(self, lib.secp256k1_ec_seckey_tweak_add, scalar)
 
     def tweak_mul(self, scalar):
         """
         Tweak the current private key by multiplying it by a 32 byte scalar
         and return a new raw private key composed of 32 bytes.
         """
-        return _tweak_private(self, lib.secp256k1_ec_privkey_tweak_mul, scalar)
+        return _tweak_private(self, lib.secp256k1_ec_seckey_tweak_mul, scalar)
 
     def ecdsa_sign(self, msg, raw=False, digest=hashlib.sha256,
                    custom_nonce=None):
