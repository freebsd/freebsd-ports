--- bin/gaeo.py.orig	2008-12-03 01:05:19.000000000 +0800
+++ bin/gaeo.py	2008-12-18 00:52:37.000000000 +0800
@@ -212,7 +212,7 @@
 
     # copy GAEO directory
     gaeo_folder = os.path.join(project_home, 'gaeo')
-    copytree(os.path.join(os.path.dirname(os.path.dirname(__file__)), template_base, 'gaeo'), gaeo_folder)
+    copytree(os.path.join('%%GAEOHOME%%', template_base, 'gaeo'), gaeo_folder)
     
     # if zipped option is enabled
     if zipped_core:
@@ -231,10 +231,10 @@
         os.chdir(os.path.join(project_home, '..'))
     
     # copy plugins directory
-    copytree(os.path.join(os.path.dirname(os.path.dirname(__file__)), template_base, 'plugins'), os.path.join(project_home, 'plugins'))
+    copytree(os.path.join('%%GAEOHOME%%', template_base, 'plugins'), os.path.join(project_home, 'plugins'))
 
     # copy sample main.py
-    copyfile(os.path.join(os.path.dirname(os.path.dirname(__file__)), template_base, 'main-sample.py'), os.path.join(project_home, 'main.py'))
+    copyfile(os.path.join('%%GAEOHOME%%', template_base, 'main-sample.py'), os.path.join(project_home, 'main.py'))
 
     # create the eclipse project file
     if create_eclipse_proj:
