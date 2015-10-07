--- spyne/server/twisted/http.py.orig	2014-06-23 22:42:15 UTC
+++ spyne/server/twisted/http.py
@@ -99,7 +99,7 @@ def _render_file(file, request):
 
     try:
         fileForReading = file.openForReading()
-    except IOError, e:
+    except IOError as e:
         import errno
 
         if e[0] == errno.EACCES:
