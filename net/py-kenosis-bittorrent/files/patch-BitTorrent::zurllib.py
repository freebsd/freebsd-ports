--- BitTorrent/zurllib.py.orig	Thu Dec  9 10:36:43 2004
+++ BitTorrent/zurllib.py	Thu Dec  9 10:38:19 2004
@@ -35,7 +35,14 @@
         if DEBUG: 
              pprint.pprint(headers.dict)
         url = fp.url
-        return addinfourldecompress(fp, headers, url)
+	resp = addinfourldecompress(fp, headers, url)
+	# As of Python 2.4 http_open response also has 'code' and 'msg'
+	# members, and HTTPErrorProcessor breaks if they don't exist.
+	if 'code' in dir(fp):
+	  resp.code = fp.code
+	if 'msg' in dir(fp):
+	  resp.msg = fp.msg
+	return resp
 
 
 class addinfourldecompress(addinfourl):
