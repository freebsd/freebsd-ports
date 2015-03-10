This patch is fixing new blocklist plugin incompatibility with newer
versions of Twisted. The fix will be included in deluge 1.3.12.

References:
 * bug-report: http://dev.deluge-torrent.org/ticket/2737
 * commit: http://dev.deluge-torrent.org/changeset/d40dfcd53c243

Index: deluge/httpdownloader.py
===================================================================
--- deluge/httpdownloader.py	(revision 8bf18d6694db24e04cb65f20f2e219ec14043f8e)
+++ deluge/httpdownloader.py	(revision d40dfcd53c2439de121ddaff476e66194dc2c738)
@@ -147,5 +147,5 @@
         # Only use the basename
         filename = os.path.basename(filename)
-        
+
     filename = filename.strip()
     if filename.startswith(".") or ";" in filename or "|" in filename:
@@ -193,15 +193,20 @@
         headers["accept-encoding"] = "deflate, gzip, x-gzip"
 
-    # In twisted 13.1.0 the _parse() function was replaced by the _URI class 
-    if hasattr(client, '_parse'):
+    # In Twisted 13.1.0 _parse() function replaced by _URI class.
+    # In Twisted 15.0.0 _URI class renamed to URI.
+    if hasattr(client, "_parse"):
         scheme, host, port, path = client._parse(url)
     else:
-        from twisted.web.client import _URI
-        uri = _URI.fromBytes(url)
+        try:
+            from twisted.web.client import _URI as URI
+        except ImportError:
+            from twisted.web.client import URI
+
+        uri = URI.fromBytes(url)
         scheme = uri.scheme
         host = uri.host
         port = uri.port
         path = uri.path
-        
+
     factory = HTTPDownloader(url, filename, callback, headers, force_filename, allow_compression)
     if scheme == "https":
