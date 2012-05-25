--- ./scripts/PythonSerializer.py.orig	2012-04-04 17:46:44.385371264 +0200
+++ ./scripts/PythonSerializer.py	2012-04-05 00:32:11.175489615 +0200
@@ -85,8 +85,8 @@
 		assert root_type
 		#TODO: displayname, how are translation handled? on trig level or on python level?
 		stream.write(
-			"Symbol('%s', parent=%r, uri='%s', display_name='%s', doc='%s', auto_resolve=False)\n" %(name, 
-				root_type, symbol, display_name, doc)
+			str("Symbol('%s', parent=%r, uri='%s', display_name='%s', doc='%s', auto_resolve=False)\n" %(name, 
+				root_type, symbol, display_name, doc))
 		)
 		
 
