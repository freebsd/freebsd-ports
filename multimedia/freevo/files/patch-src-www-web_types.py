--- src/www/web_types.py.orig	2009-05-07 13:34:38.000000000 -0400
+++ src/www/web_types.py	2010-12-05 10:54:51.000000000 -0500
@@ -36,7 +36,6 @@
 import config
 import socket
 
-from twisted.web.woven import page
 from twisted.web.resource import Resource
 from tv.record_client import RecordClient
 
@@ -71,23 +70,6 @@
 
 
 
-class FreevoPage(page.Page):
-    """
-    """
-    def __init__(self, model=None, template=None):
-        #print 'FreevoPage.__init__(model=%r, template=%r)' % (model, template)
-
-        if not model:
-            model = {'foo': 'bar'}
-        if not template:
-            template = '<html><head><title>ERROR</title></head>' + \
-                       '<body>ERROR: no template</body></html>'
-
-        page.Page.__init__(self, model, template=template)
-
-        self.addSlash = 0
-
-
 class FreevoResource(Resource):
     """
     Base class of webpages which handels the authentication.
