--- webapp/graphite/graphlot/views.py.orig	2014-09-14 03:00:52 UTC
+++ webapp/graphite/graphlot/views.py
@@ -52,7 +52,7 @@
             ) for timeseries in seriesList ]
     if not result:
         raise Http404
-    return HttpResponse(json.dumps(result), mimetype="application/json")
+    return HttpResponse(json.dumps(result), content_type="application/json")
 
 
 def find_metric(request):
@@ -61,11 +61,11 @@
         query = str( request.REQUEST['q'] )
     except:
         return HttpResponseBadRequest(
-            content="Missing required parameter 'q'", mimetype="text/plain")
+            content="Missing required parameter 'q'", content_type="text/plain")
 
     matches = list( STORE.find(query+"*") )
     content = "\n".join([node.metric_path for node in matches ])
-    response = HttpResponse(content, mimetype='text/plain')
+    response = HttpResponse(content, content_type='text/plain')
 
     return response
 
@@ -118,7 +118,7 @@
 
   index_file.close()
   result_string = ','.join(results)
-  return HttpResponse(result_string, mimetype='text/plain')
+  return HttpResponse(result_string, content_type='text/plain')
 
 
 def myGraphLookup(request):
@@ -256,9 +256,9 @@
     jsonp = False
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
