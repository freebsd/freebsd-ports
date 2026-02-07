--- setup.py.orig	2019-01-30 15:58:00 UTC
+++ setup.py
@@ -6,14 +6,9 @@ from distutils.core import setup
 autostart_path = '/etc/xdg/autostart'
 
 import sys
-backup_path_0 = sys.path[0]
-sys.path[0] = backup_path_0 + '/lib'
-#from solaar import NAME, __version__
 __version__ = '0.9.2'
 NAME = 'Solaar'
 
-sys.path[0] = backup_path_0
-
 if 'install' in sys.argv:
 	# naively guess where the autostart .desktop file should be installed
 	if '--prefix' in sys.argv or any(x.startswith('--prefix=') for x in sys.argv) or '--home' in sys.argv:
@@ -25,7 +20,7 @@ if 'install' in sys.argv:
 		autostart_path = path.join(xdg_config_home, 'autostart')
 		del environ, path, xdg_config_home
 
-del sys, backup_path_0
+del sys
 
 
 def _data_files():
@@ -39,7 +34,6 @@ def _data_files():
 		yield _dirname(mo), [mo]
 
 	yield 'share/applications', ['share/applications/solaar.desktop']
-	yield autostart_path, ['share/applications/solaar.desktop']
 
 	del _dirname
 
