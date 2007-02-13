--- src/roster_window.py.orig	Wed Nov 22 03:01:11 2006
+++ src/roster_window.py	Sun Nov 26 17:01:25 2006
@@ -18,6 +18,7 @@
 import gtk
 import gobject
 import os
+import sys
 import time
 import urllib
 
@@ -744,9 +745,9 @@
 			if os.path.exists('history_manager.exe'): # user is running stable
 				helpers.exec_command('history_manager.exe')
 			else: # user is running svn
-				helpers.exec_command('python history_manager.py')
+				helpers.exec_command('%s history_manager.py' % (sys.executable,))
 		else: # Unix user
-			helpers.exec_command('python history_manager.py &')
+			helpers.exec_command('%s history_manager.py &' % (sys.executable,))
 
 	def get_and_connect_advanced_menuitem_menu(self, account):
 		'''adds FOR ACCOUNT options'''
