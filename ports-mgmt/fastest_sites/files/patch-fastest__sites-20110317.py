--- fastest_sites-20110317.py.orig	2018-01-03 06:06:26 UTC
+++ fastest_sites-20110317.py
@@ -61,7 +61,7 @@ class AsyncConnect(asyncore.dispatcher):
 
   def ParseURL(self):
     #print "Url: %s" % self._url
-    (scheme, remainder) = self._url.split(":", 2)
+    (scheme, remainder) = self._url.split(":", 1)
     (host, unused_path) = urllib.splithost(remainder)
     self._host = host
     self._port = AsyncConnect.schemes[scheme.lower()]
