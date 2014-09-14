--- webapp/graphite/browser/views.py.orig	2014-09-14 03:00:52 UTC
+++ webapp/graphite/browser/views.py
@@ -77,7 +77,7 @@
 
   index_file.close()
   result_string = ','.join(results)
-  return HttpResponse(result_string, mimetype='text/plain')
+  return HttpResponse(result_string, content_type='text/plain')
 
 
 def myGraphLookup(request):
@@ -254,9 +254,9 @@
   #json = str(nodes) #poor man's json encoder for simple types
   json_data = json.dumps(nodes)
   if jsonp:
-    response = HttpResponse("%s(%s)" % (jsonp, json_data),mimetype="text/javascript")
+    response = HttpResponse("%s(%s)" % (jsonp, json_data),content_type="text/javascript")
   else:
-    response = HttpResponse(json_data,mimetype="application/json")
+    response = HttpResponse(json_data,content_type="application/json")
   response['Pragma'] = 'no-cache'
   response['Cache-Control'] = 'no-cache'
   return response
