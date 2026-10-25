Description: Make the sndhdr import optional; sndhdr was removed in
  Python 3.13.  Without it, the Audio syntax validator checks the .au
  magic number itself, which is the test sndhdr.test_au() starts with.
Issue ID: none (upstream inactive)
Changeset: none
TODO: Drop once a release no longer imports sndhdr.

--- web2ldap/app/schema/syntaxes.py.orig	2022-07-23 19:42:05 UTC
+++ web2ldap/app/schema/syntaxes.py
@@ -16,7 +16,12 @@ import binascii
 import sys
 import re
 import imghdr
-import sndhdr
+try:
+    import sndhdr
+except ImportError:
+    # removed in Python 3.13; Audio._validate() falls back to the .au
+    # magic number check that sndhdr.test_au() starts with
+    sndhdr = None
 import urllib.parse
 import uuid
 import datetime
@@ -489,6 +494,8 @@ class Audio(Binary):
     file_ext: str = 'au'
 
     def _validate(self, attr_value: bytes) -> bool:
+        if sndhdr is None:
+            return attr_value[:4] in (b'.snd', b'\0ds.', b'dns.')
         with BytesIO(attr_value) as fileobj:
             res = sndhdr.test_au(attr_value, fileobj)
         return res is not None
