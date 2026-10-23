Description: Use hmac.compare_digest and urllib.parse instead of helpers
  removed in Werkzeug 2.1 and 3.0.
Issue ID: none
Changeset: https://github.com/pallets-eco/secure-cookie/commit/4cf2f73
  (partly)
TODO: Upstream is dead (no commits since 2022-10); keep locally.

--- src/secure_cookie/cookie.py.orig	2026-10-12 02:46:19 UTC
+++ src/secure_cookie/cookie.py
@@ -102,14 +102,13 @@ from hashlib import sha1 as _default_hash
 import json as _json
 from datetime import datetime
 from hashlib import sha1 as _default_hash
+from hmac import compare_digest
 from hmac import new as hmac
 from numbers import Number
 from time import time
 
-from werkzeug.security import safe_str_cmp
-from werkzeug.urls import url_quote_plus
-from werkzeug.urls import url_unquote_plus
-from werkzeug.utils import detect_utf_encoding
+from urllib.parse import quote_plus as url_quote_plus
+from urllib.parse import unquote_plus as url_unquote_plus
 
 from ._compat import to_bytes
 from ._compat import to_native
@@ -144,11 +143,6 @@ class _JSONModule(object):
 
     @staticmethod
     def loads(s, **kw):
-        if isinstance(s, bytes):
-            # Needed for Python < 3.6
-            encoding = detect_utf_encoding(s)
-            s = s.decode(encoding)
-
         return _json.loads(s, **kw)
 
 
@@ -341,7 +335,7 @@ class SecureCookie(ModificationTrackingDict):
             except TypeError:
                 items = client_hash = None
 
-            if items is not None and safe_str_cmp(client_hash, mac.digest()):
+            if items is not None and compare_digest(client_hash, mac.digest()):
                 try:
                     for key, value in items.items():
                         items[key] = cls.unquote(value)
