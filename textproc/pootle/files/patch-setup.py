--- setup.py.orig	2010-08-26 13:51:15.000000000 -0500
+++ setup.py	2010-09-15 14:05:20.000000000 -0500
@@ -65,8 +65,7 @@
 
 def collect_options():
     data_files = [
-        (INSTALL_CONFIG_DIR, ['localsettings.py']),
-        (INSTALL_DOC_DIR, ['wsgi.py', 'ChangeLog', 'COPYING', 'README', 'INSTALL']),
+        (INSTALL_CONFIG_DIR, ['localsettings.py.sample']),
         (INSTALL_WORKING_DIR + '/dbs', []), # Create the empty "dbs" dir
     ] + list_tree(INSTALL_DATA_DIR, 'templates') + list_tree(INSTALL_DATA_DIR, 'html') + \
         list_tree(INSTALL_WORKING_DIR, 'po') + list_tree(INSTALL_DATA_DIR, 'mo')
