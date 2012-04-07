--- extra/PythonSerializer.py.orig	2011-09-21 13:57:53.000000000 -0400
+++ extra/PythonSerializer.py	2012-04-07 05:36:04.507729012 -0400
@@ -85,8 +85,8 @@
 		assert root_type
 		#TODO: displayname, how are translation handled? on trig level or on python level?
 		stream.write(
-			"Symbol('%s', parent=%r, uri='%s', display_name='%s', doc='%s', auto_resolve=False)\n" %(name, 
-				root_type, symbol, display_name, doc)
+			str("Symbol('%s', parent=%r, uri='%s', display_name='%s', doc='%s', auto_resolve=False)\n" %(name, 
+				root_type, symbol, display_name, doc))
 		)
 		
 
