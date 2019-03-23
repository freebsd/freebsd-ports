--- setup.py.orig	2019-03-22 05:20:14 UTC
+++ setup.py
@@ -153,12 +153,13 @@ def _download_jquery_to(dest):
     sha = 'f8233674366ab36b2c34c577ec77a3d70cac75d2e387d8587f3836345c0f624d'
     if not os.path.exists(os.path.join(dest, "jquery-ui-1.12.1")):
         _makedirs(dest, exist_ok=True)
-        try:
-            buff = download_or_cache(url, sha)
-        except Exception:
-            raise IOError("Failed to download jquery-ui.  Please download " +
-                          "{url} and extract it to {dest}.".format(
-                              url=url, dest=dest))
+        buff = os.path.join("%%DISTDIR%%", "jquery-ui-1.12.1.zip")
+#        try:
+#            buff = download_or_cache(url, sha)
+#        except Exception:
+#            raise IOError("Failed to download jquery-ui.  Please download " +
+#                          "{url} and extract it to {dest}.".format(
+#                              url=url, dest=dest))
         with ZipFile(buff) as zf:
             zf.extractall(dest)
 
