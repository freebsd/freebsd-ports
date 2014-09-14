--- webapp/graphite/whitelist/views.py.orig	2014-09-14 03:00:52 UTC
+++ webapp/graphite/whitelist/views.py
@@ -25,19 +25,19 @@
   whitelist = load_whitelist()
   new_whitelist = whitelist | metrics
   save_whitelist(new_whitelist)
-  return HttpResponse(mimetype="text/plain", content="OK")
+  return HttpResponse(content_type="text/plain", content="OK")
 
 def remove(request):
   metrics = set( request.POST['metrics'].split() )
   whitelist = load_whitelist()
   new_whitelist = whitelist - metrics
   save_whitelist(new_whitelist)
-  return HttpResponse(mimetype="text/plain", content="OK")
+  return HttpResponse(content_type="text/plain", content="OK")
 
 def show(request):
   whitelist = load_whitelist()
   members = '\n'.join( sorted(whitelist) )
-  return HttpResponse(mimetype="text/plain", content=members)
+  return HttpResponse(content_type="text/plain", content=members)
 
 def load_whitelist():
   fh = open(settings.WHITELIST_FILE, 'rb')
