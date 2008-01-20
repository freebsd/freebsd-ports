--- src/roster_window.py.orig	2007-10-02 03:05:04.000000000 +0400
+++ src/roster_window.py	2007-10-02 18:51:50.000000000 +0400
@@ -846,9 +846,9 @@
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
