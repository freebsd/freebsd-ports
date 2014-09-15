--- webapp/graphite/metrics/views.py.orig	2014-09-14 03:00:52 UTC
+++ webapp/graphite/metrics/views.py
@@ -71,16 +71,16 @@
     for m in sorted(matches)
   ]
   if jsonp:
-    return HttpResponse("%s(%s)" % (jsonp, json.dumps(matches)), mimetype='text/javascript')
+    return HttpResponse("%s(%s)" % (jsonp, json.dumps(matches)), content_type='text/javascript')
   else:
-    return HttpResponse(json.dumps(matches), mimetype='application/json')
+    return HttpResponse(json.dumps(matches), content_type='application/json')
 
 
 def search_view(request):
   try:
     query = str( request.REQUEST['query'] )
   except:
-    return HttpResponseBadRequest(content="Missing required parameter 'query'", mimetype="text/plain")
+    return HttpResponseBadRequest(content="Missing required parameter 'query'", content_type="text/plain")
   search_request = {
     'query' : query,
     'max_results' : int( request.REQUEST.get('max_results', 25) ),
@@ -91,7 +91,7 @@
 
   results = sorted(searcher.search(**search_request))
   result_data = json.dumps( dict(metrics=results) )
-  return HttpResponse(result_data, mimetype='application/json')
+  return HttpResponse(result_data, content_type='application/json')
 
 
 def context_view(request):
@@ -99,7 +99,7 @@
     contexts = []
 
     if not 'metric' not in request.GET:
-      return HttpResponse('{ "error" : "missing required parameter \"metric\"" }', mimetype='application/json')
+      return HttpResponse('{ "error" : "missing required parameter \"metric\"" }', content_type='application/json')
 
     for metric in request.GET.getlist('metric'):
       try:
@@ -110,19 +110,19 @@
         contexts.append({ 'metric' : metric, 'context' : context })
 
     content = json.dumps( { 'contexts' : contexts } )
-    return HttpResponse(content, mimetype='application/json')
+    return HttpResponse(content, content_type='application/json')
 
   elif request.method == 'POST':
 
     if 'metric' not in request.POST:
-      return HttpResponse('{ "error" : "missing required parameter \"metric\"" }', mimetype='application/json')
+      return HttpResponse('{ "error" : "missing required parameter \"metric\"" }', content_type='application/json')
 
     newContext = dict( item for item in request.POST.items() if item[0] != 'metric' )
 
     for metric in request.POST.getlist('metric'):
       STORE.get(metric).updateContext(newContext)
 
-    return HttpResponse('{ "success" : true }', mimetype='application/json')
+    return HttpResponse('{ "success" : true }', content_type='application/json')
 
   else:
     return HttpResponseBadRequest("invalid method, must be GET or POST")
@@ -140,7 +140,7 @@
   try:
     query = str( request.REQUEST['query'] )
   except:
-    return HttpResponseBadRequest(content="Missing required parameter 'query'", mimetype="text/plain")
+    return HttpResponseBadRequest(content="Missing required parameter 'query'", content_type="text/plain")
 
   if '.' in query:
     base_path = query.rsplit('.', 1)[0] + '.'
@@ -175,11 +175,11 @@
 
   if format == 'treejson':
     content = tree_json(matches, base_path, wildcards=profile.advancedUI or wildcards, contexts=contexts)
-    response = HttpResponse(content, mimetype='application/json')
+    response = HttpResponse(content, content_type='application/json')
 
   elif format == 'pickle':
     content = pickle_nodes(matches, contexts=contexts)
-    response = HttpResponse(content, mimetype='application/pickle')
+    response = HttpResponse(content, content_type='application/pickle')
 
   elif format == 'completer':
     #if len(matches) == 1 and (not matches[0].isLeaf()) and query == matches[0].metric_path + '*': # auto-complete children
@@ -196,10 +196,10 @@
       results.append(wildcardNode)
 
     content = json.dumps({ 'metrics' : results })
-    response = HttpResponse(content, mimetype='application/json')
+    response = HttpResponse(content, content_type='application/json')
 
   else:
-    return HttpResponseBadRequest(content="Invalid value for 'format' parameter", mimetype="text/plain")
+    return HttpResponseBadRequest(content="Invalid value for 'format' parameter", content_type="text/plain")
 
   response['Pragma'] = 'no-cache'
   response['Cache-Control'] = 'no-cache'
@@ -235,7 +235,7 @@
     'results' : results
   }
 
-  response = HttpResponse(json.dumps(result), mimetype='application/json')
+  response = HttpResponse(json.dumps(result), content_type='application/json')
   response['Pragma'] = 'no-cache'
   response['Cache-Control'] = 'no-cache'
   return response
@@ -252,7 +252,7 @@
       log.exception()
       results[metric] = dict(error="Unexpected error occurred in CarbonLink.get_metadata(%s, %s)" % (metric, key))
 
-  return HttpResponse(json.dumps(results), mimetype='application/json')
+  return HttpResponse(json.dumps(results), content_type='application/json')
 
 
 def set_metadata_view(request):
@@ -287,7 +287,7 @@
   else:
     results = dict(error="Invalid request method")
 
-  return HttpResponse(json.dumps(results), mimetype='application/json')
+  return HttpResponse(json.dumps(results), content_type='application/json')
 
 
 def tree_json(nodes, base_path, wildcards=False, contexts=False):
