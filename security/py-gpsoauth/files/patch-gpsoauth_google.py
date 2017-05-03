--- gpsoauth/google.py.orig	2017-02-18 18:11:10 UTC
+++ gpsoauth/google.py
@@ -1,8 +1,8 @@
 import base64
 import hashlib
 
-from Cryptodome.PublicKey import RSA
-from Cryptodome.Cipher import PKCS1_OAEP
+from Crypto.PublicKey import RSA
+from Crypto.Cipher import PKCS1_OAEP
 
 from .util import bytes_to_long, long_to_bytes
 
