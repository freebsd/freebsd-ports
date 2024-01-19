--- merkletools/__init__.py.orig	2024-01-16 17:39:29 UTC
+++ merkletools/__init__.py
@@ -1,11 +1,5 @@ import binascii
 import hashlib
 import binascii
-try:
-    import sha3
-except:
-    from warnings import warn
-    warn("sha3 is not working!")
-
 
 class MerkleTools(object):
     def __init__(self, hash_type="sha256"):
