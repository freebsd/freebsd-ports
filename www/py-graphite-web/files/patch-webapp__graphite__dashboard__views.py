--- webapp/graphite/dashboard/views.py.orig	2014-09-14 03:00:52 UTC
+++ webapp/graphite/dashboard/views.py
@@ -249,4 +249,4 @@
 
 
 def json_response(obj):
-  return HttpResponse(mimetype='application/json', content=json.dumps(obj))
+  return HttpResponse(content_type='application/json', content=json.dumps(obj))
