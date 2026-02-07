--- httpbin/helpers.py.orig	2023-08-28 22:56:17 UTC
+++ httpbin/helpers.py
@@ -13,7 +13,15 @@ from hashlib import md5, sha256, sha512
 import time
 import os
 from hashlib import md5, sha256, sha512
-from werkzeug.http import parse_authorization_header
+# Can be removed when: https://github.com/psf/httpbin/issues/36 is closed
+# See also (version order is wrong):
+# https://src.fedoraproject.org/rpms/python-httpbin/c/54fe8e1f94f208b16ef0588e4eb69aaa107e9867?branch=rawhide
+from werkzeug.http import dump_header
+try:
+    from werkzeug.datastructures import Authorization
+    parse_authorization_header = Authorization.from_header
+except ImportError: # werkzeug < 2.3
+    from werkzeug.http import parse_authorization_header
 from werkzeug.datastructures import WWWAuthenticate
 
 from flask import request, make_response
@@ -466,9 +474,17 @@ def digest_challenge_response(app, qop, algorithm, sta
     ]), algorithm)
     opaque = H(os.urandom(10), algorithm)
 
-    auth = WWWAuthenticate("digest")
-    auth.set_digest('me@kennethreitz.com', nonce, opaque=opaque,
-                    qop=('auth', 'auth-int') if qop is None else (qop,), algorithm=algorithm)
-    auth.stale = stale
+    # Can be removed when: https://github.com/psf/httpbin/issues/36 is closed
+    # See also:
+    # https://src.fedoraproject.org/rpms/python-httpbin/c/54fe8e1f94f208b16ef0588e4eb69aaa107e9867?branch=rawhide
+    values = {
+        'realm': 'me@kennethreitz.com',
+        'nonce': nonce,
+        'opaque': opaque,
+        'qop': dump_header(('auth', 'auth-int') if qop is None else (qop,)),
+        'algorithm': algorithm,
+        'stale': stale,
+    }
+    auth = WWWAuthenticate("digest", values=values) 
     response.headers['WWW-Authenticate'] = auth.to_header()
     return response
