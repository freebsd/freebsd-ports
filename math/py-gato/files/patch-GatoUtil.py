--- GatoUtil.py.orig	Wed May 16 13:16:56 2001
+++ GatoUtil.py	Mon Sep  3 12:14:42 2001
@@ -40,8 +40,8 @@
 
 def extension(pathAndFile):
     """ Return ext if path/filename.ext is given """
-    import regsub
-    return regsub.split(stripPath(pathAndFile),"\.")[1]
+    import re
+    return re.split("\.", stripPath(pathAndFile))[1]
 
 def stripPath(pathAndFile):
     """ Return filename.ext if path/filename.ext is given """
