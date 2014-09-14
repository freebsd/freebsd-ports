--- webapp/graphite/render/views.py.orig	2013-08-21 17:11:04.000000000 +0000
+++ webapp/graphite/render/views.py	2014-09-14 03:52:01.676505998 +0000
@@ -116,7 +116,7 @@
 
     format = requestOptions.get('format')
     if format == 'csv':
-      response = HttpResponse(mimetype='text/csv')
+      response = HttpResponse(content_type='text/csv')
       writer = csv.writer(response, dialect='excel')
 
       for series in data:
@@ -136,16 +136,16 @@
       if 'jsonp' in requestOptions:
         response = HttpResponse(
           content="%s(%s)" % (requestOptions['jsonp'], json.dumps(series_data)),
-          mimetype='text/javascript')
+          content_type='text/javascript')
       else:
-        response = HttpResponse(content=json.dumps(series_data), mimetype='application/json')
+        response = HttpResponse(content=json.dumps(series_data), content_type='application/json')
 
       response['Pragma'] = 'no-cache'
       response['Cache-Control'] = 'no-cache'
       return response
 
     if format == 'raw':
-      response = HttpResponse(mimetype='text/plain')
+      response = HttpResponse(content_type='text/plain')
       for series in data:
         response.write( "%s,%d,%d,%d|" % (series.name, series.start, series.end, series.step) )
         response.write( ','.join(map(str,series)) )
@@ -158,7 +158,7 @@
       graphOptions['outputFormat'] = 'svg'
 
     if format == 'pickle':
-      response = HttpResponse(mimetype='application/pickle')
+      response = HttpResponse(content_type='application/pickle')
       seriesInfo = [series.getInfo() for series in data]
       pickle.dump(seriesInfo, response, protocol=-1)
 
@@ -177,7 +177,7 @@
   if useSVG and 'jsonp' in requestOptions:
     response = HttpResponse(
       content="%s(%s)" % (requestOptions['jsonp'], json.dumps(image)),
-      mimetype='text/javascript')
+      content_type='text/javascript')
   else:
     response = buildResponse(image, useSVG and 'image/svg+xml' or 'image/png')
 
@@ -386,7 +386,7 @@
 
 
 def buildResponse(imageData, mimetype="image/png"):
-  response = HttpResponse(imageData, mimetype=mimetype)
+  response = HttpResponse(imageData, content_type=mimetype)
   response['Cache-Control'] = 'no-cache'
   response['Pragma'] = 'no-cache'
   return response
