--- src/utils.py.orig	Mon Dec  5 16:41:53 2005
+++ src/utils.py	Mon Dec  5 16:42:18 2005
@@ -180,4 +180,8 @@
 	def flush(self):
 		self.lst = []
 
-
+def doPath(path):
+	if(path and path[0] == "/"):
+		return path
+	else:
+		return "../" + path
