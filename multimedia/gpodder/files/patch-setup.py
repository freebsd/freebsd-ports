--- ./setup.py.orig	2012-02-24 02:54:22.000000000 +0400
+++ ./setup.py	2012-05-01 11:53:17.000000000 +0400
@@ -90,7 +90,7 @@
                     return True
 
                 basename, _ = os.path.splitext(filename)
-                result = any(os.path.basename(s) == basename for s in scripts)
+                result = False
                 if not result:
                     info('Skipping manpage without script:', filename)
                 return result
