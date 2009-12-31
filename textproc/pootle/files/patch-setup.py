--- setup.py	2009-12-17 13:56:51.000000000 +0300
+++ setup.py	2009-12-17 13:57:06.000000000 +0300
@@ -54,10 +54,10 @@
 It uses the Translate Toolkit to get access to translation files and therefore
 can edit a variety of files (including PO and XLIFF files)."""
 
-INSTALL_CONFIG_DIR = '/etc/pootle'
+INSTALL_CONFIG_DIR = 'etc/pootle'
 INSTALL_DATA_DIR = 'share/pootle'
 INSTALL_DOC_DIR = 'share/doc/pootle'
-INSTALL_WORKING_DIR = '/var/lib/pootle'
+INSTALL_WORKING_DIR = '/var/db/pootle'
 
 ###############################################################################
 # HELPER FUNCTIONS
@@ -65,7 +65,7 @@
 
 def collect_options():
     data_files = [
-        (INSTALL_CONFIG_DIR, ['localsettings.py']),
+        (INSTALL_CONFIG_DIR, ['localsettings.py.sample']),
         (INSTALL_DOC_DIR, ['wsgi.py', 'ChangeLog', 'COPYING', 'README', 'INSTALL']),
         (INSTALL_WORKING_DIR + '/dbs', []) # Create the empty "dbs" dir
     ] + list_tree(INSTALL_DATA_DIR, 'templates') + list_tree(INSTALL_DATA_DIR, 'html') + \
