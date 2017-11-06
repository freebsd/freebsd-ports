--- puppetboard/app.py.orig
+++ puppetboard/app.py
@@ -114,7 +114,7 @@
     code = 204
     description = '<p>No content</p'
 
-abort.mapping[204] = NoContent
+# abort.mapping[204] = NoContent
 
 try:
     @app.errorhandler(204)
