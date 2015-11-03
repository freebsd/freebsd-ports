--- setup.py.orig	2015-10-21 20:39:22 UTC
+++ setup.py
@@ -44,7 +44,10 @@ def find_files(topdirs, py = False):
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
