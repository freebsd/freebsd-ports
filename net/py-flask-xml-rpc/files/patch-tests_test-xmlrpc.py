Obtained-From: https://bitbucket.org/leafstorm/flask-xml-rpc/pull-requests/2/added-python3-support-alongside-python2/commits

# HG changeset patch
# User Maxime "Pepe_" Buquet <pep+code@bouah.net>
# Date 1425540278 -32400
# Node ID 9da0e2bcfe5e32a1db95b639f41f67d3e1a43b80
# Parent  06a6c81e3a98ecb647e729e239f5de11814901d3
Added Python3 support alongside Python2

--- tests/test-xmlrpc.py.orig	2015-03-05 00:00:00 UTC
+++ tests/test-xmlrpc.py
@@ -7,12 +7,19 @@
 :copyright: (c) 2010 by Matthew "LeafStorm" Frazier.
 :license: MIT, see LICENSE for more details.
 """
-import xmlrpclib
 from flask import Flask
 from flaskext.xmlrpc import (XMLRPCHandler, XMLRPCNamespace, Fault,
                              dump_method_call, load_method_response,
                              test_xmlrpc_call, XMLRPCTester)
 
+import sys
+PY2 = sys.version_info[0] == 2
+
+if PY2:
+    import xmlrpclib
+else:
+    import xmlrpc.client as xmlrpclib
+
 
 def hello(name='world'):
     if not name:
@@ -39,7 +46,11 @@
         handler = XMLRPCHandler('api')
         app = Flask(__name__)
         handler.connect(app, '/api')
-        assert app.view_functions[handler.endpoint_name].im_self is handler
+        if PY2:
+            app_handler = app.view_functions[handler.endpoint_name].im_self
+        else:
+            app_handler = app.view_functions[handler.endpoint_name].__self__
+        assert app_handler is handler
     
     def test_register(self):
         handler = XMLRPCHandler('api')
