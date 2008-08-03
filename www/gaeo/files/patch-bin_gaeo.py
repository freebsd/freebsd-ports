--- bin/gaeo.py.orig	2008-07-24 15:24:37.000000000 +0800
+++ bin/gaeo.py	2008-07-24 15:25:07.000000000 +0800
@@ -196,7 +196,7 @@
     create_file(os.path.join(project_home, 'favicon.ico'), [])
 
     # copy GAEO directory
-    copytree(os.path.join(os.path.dirname(__file__), '..', 'gaeo'), os.path.join(project_home, 'gaeo'))
+    copytree(os.path.join('%%DATADIR%%', 'gaeo'), os.path.join(project_home, 'gaeo'))
 
     # create the eclipse project file
     if create_eclipse_proj:
