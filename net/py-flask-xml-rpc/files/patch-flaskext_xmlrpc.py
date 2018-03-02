Obtained-From: https://bitbucket.org/leafstorm/flask-xml-rpc/pull-requests/2/added-python3-support-alongside-python2/commits

# HG changeset patch
# User Maxime "Pepe_" Buquet <pep+code@bouah.net>
# Date 1425540278 -32400
# Node ID 9da0e2bcfe5e32a1db95b639f41f67d3e1a43b80
# Parent  06a6c81e3a98ecb647e729e239f5de11814901d3
Added Python3 support alongside Python2

--- flaskext/xmlrpc.py.orig	2015-03-05 00:00:00 UTC
+++ flaskext/xmlrpc.py
@@ -10,9 +10,16 @@
 """
 
 from flask import request, current_app
-from SimpleXMLRPCServer import SimpleXMLRPCDispatcher as Dispatcher
 import sys
-import xmlrpclib
+
+if sys.version_info[0] == 2:
+    from SimpleXMLRPCServer import SimpleXMLRPCDispatcher as Dispatcher
+    import xmlrpclib
+    string_types = basestring
+else:
+    from xmlrpc.server import SimpleXMLRPCDispatcher as Dispatcher
+    import xmlrpc.client as xmlrpclib
+    string_types = str
 
 Fault = xmlrpclib.Fault
 
@@ -97,7 +104,7 @@
                      If not given, the function's :obj:`__name__` attribute
                      will be used.
         """
-        if isinstance(function, basestring):
+        if isinstance(function, string_types):
             return lambda fn: self.register_function(fn, function)
         return Dispatcher.register_function(self, function, name)
     
@@ -198,7 +205,7 @@
                      If not given, the function's :obj:`__name__` attribute
                      will be used.
         """
-        if isinstance(function, basestring):
+        if isinstance(function, string_types):
             return lambda fn: self.register_function(fn, function)
         if name is None:
             name = function.__name__
@@ -249,7 +256,8 @@
     """
     try:
         return xmlrpclib.loads(response)[0][0]
-    except Fault, fault:
+    except Fault:
+        _, fault = sys.exec_info()[:2]
         return fault
