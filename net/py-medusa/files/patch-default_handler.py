--- default_handler.py.orig	Thu Mar 28 20:46:08 2002
+++ default_handler.py	Thu Mar 28 20:46:13 2002
@@ -169,7 +169,7 @@
 
     def set_content_type (self, path, request):
         ext = string.lower (get_extension (path))
-        typ = mimelib.guess_type(path):
+        typ = mimelib.guess_type(path)
         if typ is not None:
             request['Content-Type'] = typ
         else:
