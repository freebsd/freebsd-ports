--- httpbin/core.py.orig	2018-05-08 11:41:03 UTC
+++ httpbin/core.py
@@ -19,7 +19,7 @@ from flask import Flask, Response, request, render_tem
 from six.moves import range as xrange
 from werkzeug.datastructures import WWWAuthenticate, MultiDict
 from werkzeug.http import http_date
-from werkzeug.wrappers import BaseResponse
+from werkzeug.wrappers import Response as BaseResponse
 from werkzeug.http import parse_authorization_header
 from raven.contrib.flask import Sentry
 
