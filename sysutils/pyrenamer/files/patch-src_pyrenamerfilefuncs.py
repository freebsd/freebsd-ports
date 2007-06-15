--- src/pyrenamerfilefuncs.py.orig	Fri Jun 15 07:14:07 2007
+++ src/pyrenamerfilefuncs.py	Fri Jun 15 07:15:43 2007
@@ -39,6 +39,12 @@
     return STOP
 
 
+def escape_pattern(pattern):
+    """ Escape special chars on patterns, so glob doesn't get confused """
+    pattern = pattern.replace('[', '[[]')
+    return pattern
+
+
 def get_file_listing(dir, pattern=None):
     """ Returns the file listing of a given directory. It returns only files.
     Returns a list of [file,/path/to/file] """
@@ -49,7 +55,7 @@
         listaux = dircache.listdir(dir)
     else:
         if dir != '/': dir += '/'
-        dir += pattern
+        dir = escape_pattern(dir + pattern)
         listaux = glob.glob(dir)
     
     listaux.sort(key=str.lower)
