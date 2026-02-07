--- httpbin/core.py.orig	2023-08-28 22:56:17 UTC
+++ httpbin/core.py
@@ -32,7 +32,6 @@ except ImportError:  # werkzeug < 2.1
     from werkzeug.wrappers import Response
 except ImportError:  # werkzeug < 2.1
     from werkzeug.wrappers import BaseResponse as Response
-from werkzeug.http import parse_authorization_header
 from flasgger import Swagger, NO_SANITIZER
 
 from . import filters
@@ -47,6 +46,7 @@ from .helpers import (
     H,
     ROBOT_TXT,
     ANGRY_ASCII,
+    parse_authorization_header,
     parse_multi_value_header,
     next_stale_after_value,
     digest_challenge_response,
@@ -636,16 +636,17 @@ def redirect_to():
     args_dict = request.args.items()
     args = CaseInsensitiveDict(args_dict)
 
-    # We need to build the response manually and convert to UTF-8 to prevent
-    # werkzeug from "fixing" the URL. This endpoint should set the Location
-    # header to the exact string supplied.
+
+    # Can be removed when: https://github.com/psf/httpbin/issues/36 is closed
+    # See also:
+    # https://src.fedoraproject.org/rpms/python-httpbin/c/54fe8e1f94f208b16ef0588e4eb69aaa107e9867?branch=rawhide
     response = app.make_response("")
     response.status_code = 302
     if "status_code" in args:
         status_code = int(args["status_code"])
         if status_code >= 300 and status_code < 400:
             response.status_code = status_code
-    response.headers["Location"] = args["url"].encode("utf-8")
+    response.headers["Location"] = args["url"]
 
     return response
 
