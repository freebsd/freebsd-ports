--- ./setup.py.orig	2013-10-15 14:55:22.000000000 +0000
+++ ./setup.py	2013-12-15 21:41:37.000000000 +0000
@@ -45,7 +45,10 @@
     ret = []
     for topdir in topdirs:
         for r, _ds, fs in os.walk(topdir):
-            ret.append((r, [ os.path.join(r, f) for f in fs if (f.endswith('.py') or not py)]))
+            fl = [ os.path.join(r, f) for f in fs if (f.endswith('.py') or not py)]
+            # Do not record directories (with no regular files inside)
+            if len(fl) > 0:
+                ret.append((r, fl))
     return ret
 
 opts = {}
