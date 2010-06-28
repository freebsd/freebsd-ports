--- setup.py.orig	2009-12-02 07:33:29.000000000 -0200
+++ setup.py	2010-04-01 17:34:44.000000000 -0300
@@ -65,8 +64,7 @@
 
 def collect_options():
     data_files = [
-        (INSTALL_CONFIG_DIR, ['localsettings.py']),
-        (INSTALL_DOC_DIR, ['wsgi.py', 'ChangeLog', 'COPYING', 'README', 'INSTALL']),
+        (INSTALL_CONFIG_DIR, ['localsettings.py.sample']),
         (INSTALL_WORKING_DIR + '/dbs', []) # Create the empty "dbs" dir
     ] + list_tree(INSTALL_DATA_DIR, 'templates') + list_tree(INSTALL_DATA_DIR, 'html') + \
         list_tree(INSTALL_WORKING_DIR, 'po') + list_tree(INSTALL_DATA_DIR, 'mo')
