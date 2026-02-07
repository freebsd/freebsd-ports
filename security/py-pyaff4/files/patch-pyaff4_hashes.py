https://github.com/aff4/pyaff4/commit/af2ce19c5a2ad61d68309a856ded93cee2901ea4

--- pyaff4/hashes.py.orig	2017-12-05 20:36:26 UTC
+++ pyaff4/hashes.py
@@ -16,7 +16,7 @@ import hashlib
 from pyaff4 import lexicon
 from pyaff4.rdfvalue import *
 import hashlib
-import pyblake2
+import nacl.hash
 
 def new(datatype):
     return map[datatype]()
@@ -54,7 +54,7 @@ map = {
     lexicon.HASH_SHA256: hashlib.sha256,
     lexicon.HASH_SHA512: hashlib.sha512,
     lexicon.HASH_MD5: hashlib.md5,
-    lexicon.HASH_BLAKE2B: pyblake2.blake2b
+    lexicon.HASH_BLAKE2B: nacl.hash.blake2b
 }
 
 nameMap = {
