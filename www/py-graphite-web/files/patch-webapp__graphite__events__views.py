--- webapp/graphite/events/views.py.orig	2014-09-14 03:00:52 UTC
+++ webapp/graphite/events/views.py
@@ -65,11 +65,11 @@
         response = HttpResponse(
           "%s(%s)" % (request.REQUEST.get('jsonp'), 
               json.dumps(fetch(request), cls=EventEncoder)),
-          mimetype='text/javascript')
+          content_type='text/javascript')
     else:
         response = HttpResponse(
             json.dumps(fetch(request), cls=EventEncoder),
-            mimetype="application/json")
+            content_type="application/json")
     return response
 
 def fetch(request):
