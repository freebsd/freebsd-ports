--- BitTorrent/zurllib.py.orig	Wed Jan  5 20:41:27 2005
+++ BitTorrent/zurllib.py	Wed Jan  5 20:41:50 2005
@@ -10,7 +10,7 @@
 
 # Written by John Hoffman
 
-from httplib import HTTPConnection
+from httplib import HTTPConnection, HTTPException
 from urlparse import urlparse
 import socket
 from gzip import GzipFile
@@ -20,6 +20,15 @@
 
 MAX_REDIRECTS = 10
 
+class btHTTPcon(HTTPConnection): # attempt to add automatic connection timeout
+    def connect(self):
+        HTTPConnection.connect(self)
+        try:
+            self.sock.settimeout(30)
+        except:
+            pass
+
+
 class urlopen:
     def __init__(self, url):
         self.tries = 0
@@ -39,11 +48,14 @@
         if query:
             url += '?'+query
 #        if fragment:
-        self.connection = HTTPConnection(netloc)
-        self.connection.request('GET', url, None,
+        try:
+            self.connection = btHTTPcon(netloc)
+            self.connection.request('GET', url, None,
                                 { 'User-Agent': 'BitTorrent/' + version,
                                   'Accept-Encoding': 'gzip' } )
-        self.response = self.connection.getresponse()
+            self.response = self.connection.getresponse()
+        except HTTPException, e:
+            raise IOError, ('http error', str(e))
         status = self.response.status
         if status in (301,302):
             try:
