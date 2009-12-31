--- pootle/install_dirs.py	2009-09-03 05:52:41.000000000 +0400
+++ pootle/install_dirs.py	2009-12-16 19:49:09.000000000 +0300
@@ -1,9 +1,9 @@
 import os
 
-CONFIG_DIR  = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
-DATA_DIR    = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
+CONFIG_DIR = '/usr/local/etc/pootle'
+DATA_DIR = '/usr/local/share/pootle'
 SOURCE_DIR  = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
-WORKING_DIR = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))
+WORKING_DIR = '/var/db/pootle'
 
 def config_path(filename):
     return os.path.join(CONFIG_DIR, filename)
