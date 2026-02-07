--- setup.py.orig	2021-01-25 10:40:44 UTC
+++ setup.py
@@ -8,7 +8,6 @@ from os import path
 from glob import glob
 from os import path
 
-
 from jupyter_packaging import (
     create_cmdclass, install_npm, ensure_targets,
     combine_commands, ensure_python,
@@ -22,9 +21,6 @@ HERE = path.dirname(path.abspath(__file__))
 name = 'ipygany'
 
 HERE = path.dirname(path.abspath(__file__))
-
-# Ensure a valid python version
-ensure_python('>=3.6')
 
 # Get our version
 version = get_version(path.join(name, '_version.py'))
