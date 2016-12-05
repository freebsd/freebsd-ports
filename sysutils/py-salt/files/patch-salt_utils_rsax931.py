--- salt/utils/rsax931.py.orig	2016-11-22 17:52:40 UTC
+++ salt/utils/rsax931.py
@@ -16,6 +16,11 @@ import salt.utils
 from ctypes import cdll, c_char_p, c_int, c_void_p, pointer, create_string_buffer
 from ctypes.util import find_library
 
+# Constants taken from openssl-1.1.0c/include/openssl/crypto.h
+OPENSSL_INIT_ADD_ALL_CIPHERS = 0x00000004
+OPENSSL_INIT_ADD_ALL_DIGESTS = 0x00000008
+OPENSSL_INIT_NO_LOAD_CONFIG = 0x00000080
+
 
 def _load_libcrypto():
     '''
@@ -62,8 +67,15 @@ def _init_libcrypto():
     libcrypto.RSA_private_encrypt.argtypes = (c_int, c_char_p, c_char_p, c_void_p, c_int)
     libcrypto.RSA_public_decrypt.argtypes = (c_int, c_char_p, c_char_p, c_void_p, c_int)
 
-    libcrypto.OPENSSL_no_config()
-    libcrypto.OPENSSL_add_all_algorithms_noconf()
+    try:
+        if libcrypto.OPENSSL_init_crypto(OPENSSL_INIT_NO_LOAD_CONFIG |
+                                         OPENSSL_INIT_ADD_ALL_CIPHERS |
+                                         OPENSSL_INIT_ADD_ALL_DIGESTS, None) != 1:
+            raise OSError("Failed to initialize OpenSSL library (OPENSSL_init_crypto failed)")
+    except AttributeError:
+        # Support for OpenSSL < 1.1 (OPENSSL_API_COMPAT < 0x10100000L)
+        libcrypto.OPENSSL_no_config()
+        libcrypto.OPENSSL_add_all_algorithms_noconf()
 
     return libcrypto
 
