--- diffoscope/comparators/directory.py.orig	2016-01-30 11:54:52 UTC
+++ diffoscope/comparators/directory.py
@@ -72,8 +72,11 @@ def lsattr(path):
 class Getfacl(Command):
     @tool_required('getfacl')
     def cmdline(self):
-        return ['getfacl', '-p', '-c', self.path]
-
+        osname = os.uname()[0]
+        if osname == 'Linux':
+            return ['getfacl', '-p', '-c', self.path]
+        else: # FreeBSD
+            return ['getfacl', '-q', '-h', self.path]
 
 def compare_meta(path1, path2):
     logger.debug('compare_meta(%s, %s)', path1, path2)
@@ -84,17 +87,19 @@ def compare_meta(path1, path2):
         logger.warn("'stat' not found! Is PATH wrong?")
     if os.path.islink(path1) or os.path.islink(path2):
         return [d for d in differences if d is not None]
-    try:
-        lsattr1 = lsattr(path1)
-        lsattr2 = lsattr(path2)
-        differences.append(Difference.from_text(
-                               lsattr1, lsattr2, path1, path2, source="lattr"))
-    except RequiredToolNotFound:
-        logger.info("Unable to find 'lsattr'.")
-    try:
-        differences.append(Difference.from_command(Getfacl, path1, path2))
-    except RequiredToolNotFound:
-        logger.info("Unable to find 'getfacl'.")
+    osname = os.uname()[0]
+    if osname == "Linux" or osname == "FreeBSD":
+        try:
+            lsattr1 = lsattr(path1)
+            lsattr2 = lsattr(path2)
+            differences.append(Difference.from_text(
+                                   lsattr1, lsattr2, path1, path2, source="lattr"))
+        except RequiredToolNotFound:
+            logger.info("Unable to find 'lsattr'.")
+        try:
+            differences.append(Difference.from_command(Getfacl, path1, path2))
+        except RequiredToolNotFound:
+            logger.info("Unable to find 'getfacl'.")
     return [d for d in differences if d is not None]
 
 
