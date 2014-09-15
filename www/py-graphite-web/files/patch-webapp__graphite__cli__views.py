--- webapp/graphite/cli/views.py.orig	2014-09-14 03:00:52 UTC
+++ webapp/graphite/cli/views.py
@@ -40,7 +40,7 @@
 def evaluate(request):
   if 'commandInput' not in request.GET:
     output = commands.stderr("No commandInput parameter!")
-    return HttpResponse(output, mimetype='text/plain')
+    return HttpResponse(output, content_type='text/plain')
 
   #Variable substitution
   profile = getProfile(request)
@@ -59,7 +59,7 @@
       cmd = cmd[:i] + my_vars[var] + cmd[j:]
     else:
       output = commands.stderr("Unknown variable %s" % var)
-      return HttpResponse(output, mimetype='text/plain')
+      return HttpResponse(output, content_type='text/plain')
 
   if cmd == '?': cmd = 'help'
 
@@ -68,13 +68,13 @@
 
     if not tokens.command:
       output = commands.stderr("Invalid syntax")
-      return HttpResponse(output, mimetype='text/plain')
+      return HttpResponse(output, content_type='text/plain')
 
     handler_name = '_' + tokens.command
     handler = vars(commands).get(handler_name)
     if handler is None:
       output = commands.stderr("Unknown command")
-      return HttpResponse(output, mimetype='text/plain')
+      return HttpResponse(output, content_type='text/plain')
 
     args = dict( tokens.items() )
     del args['command']
@@ -89,4 +89,4 @@
   profile.history = '\n'.join(history)
   profile.save()
 
-  return HttpResponse(output, mimetype='text/plain')
+  return HttpResponse(output, content_type='text/plain')
