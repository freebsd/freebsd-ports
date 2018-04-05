--- qtiplot/qtiplotrc.py.orig	2011-07-06 06:37:50 UTC
+++ qtiplot/qtiplotrc.py
@@ -37,7 +37,10 @@ def import_to_global(modname, attrs=None
 	"""
 	import sys
 	import os
-	sys.path.append(os.path.dirname(__file__))
+	try:
+		sys.path.append(os.path.dirname(__file__))
+	except:
+		pass
 	mod = __import__(modname)
 	for submod in modname.split(".")[1:]:
 		mod = getattr(mod, submod)
