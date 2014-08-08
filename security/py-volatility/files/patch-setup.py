--- setup.py.orig	2014-08-03 18:09:32 +0000
+++ setup.py
@@ -44,7 +44,10 @@
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
