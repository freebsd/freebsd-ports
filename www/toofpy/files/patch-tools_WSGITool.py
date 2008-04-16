--- tools/WSGITool.py.vanilla	2008-02-17 23:30:03.000000000 +0100
+++ tools/WSGITool.py	2008-02-17 23:31:16.000000000 +0100
@@ -49,14 +49,17 @@
 	haswsgi = 0
 	class BaseHandler: pass
 
-if config.django:
-	try:
-		from django.core import management
-		from django.core.handlers.wsgi import WSGIHandler
-		hasdjango = 1
-	except ImportError:
-		hasdjango = 0
-else: hasdjango = 0
+try:
+	if config.django:
+		try:
+			from django.core import management
+			from django.core.handlers.wsgi import WSGIHandler
+			hasdjango = 1
+		except ImportError:
+			hasdjango = 0
+	else: hasdjango = 0
+except:
+	hasdjango = 0
 
 try:
 	True
