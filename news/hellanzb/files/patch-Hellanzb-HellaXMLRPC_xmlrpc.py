--- Hellanzb/HellaXMLRPC/xmlrpc.py.orig	2007-03-27 08:20:43.000000000 +0400
+++ Hellanzb/HellaXMLRPC/xmlrpc.py	2012-01-21 20:31:29.000000000 +0400
@@ -31,7 +31,7 @@
 from twisted.python import log, reflect
 
 import twisted.copyright
-if twisted.copyright.version >= '2.0.0':
+if twisted.copyright.version >= '2.0.0' or twisted.copyright.version >= '10.0.0':
     from twisted.web import http
 else:
     from twisted.protocols import http
