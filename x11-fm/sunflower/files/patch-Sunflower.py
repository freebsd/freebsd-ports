--- Sunflower.py.orig	2016-09-05 09:28:20 UTC
+++ Sunflower.py
@@ -25,7 +25,7 @@ import subprocess
 default_paths = os.pathsep.join(('/bin', '/usr/bin', '/usr/local/bin'))
 search_paths = os.environ.get('PATH', default_paths).split(os.pathsep)
 interpreter_list = ('python2.9', 'python2.8', 'python2.7', 'python2.6')
-application_file = os.path.join(os.path.dirname(sys.argv[0]), 'application', 'main.py')
+application_file = os.path.join(os.path.dirname(sys.argv[0]), '%%DATADIR%%/application', 'main.py')
 
 def _can_execute(path):
 	"""Check if specified path can be executed"""
