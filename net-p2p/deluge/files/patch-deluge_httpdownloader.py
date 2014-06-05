--- ./deluge/httpdownloader.py.orig	2013-02-25 21:01:07.000000000 +0400
+++ ./deluge/httpdownloader.py	2014-06-05 12:56:06.000000000 +0400
@@ -192,7 +192,17 @@
             headers = {}
         headers["accept-encoding"] = "deflate, gzip, x-gzip"
 
-    scheme, host, port, path = client._parse(url)
+    # In twisted 13.1.0 the _parse() function was replaced by the _URI class 
+    if hasattr(client, '_parse'):
+        scheme, host, port, path = client._parse(url)
+    else:
+        from twisted.web.client import _URI
+        uri = _URI.fromBytes(url)
+        scheme = uri.scheme
+        host = uri.host
+        port = uri.port
+        path = uri.path
+
     factory = HTTPDownloader(url, filename, callback, headers, force_filename, allow_compression)
     if scheme == "https":
         from twisted.internet import ssl
