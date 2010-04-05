--- setup.py.orig	2009-12-02 07:33:29.000000000 -0200
+++ setup.py	2010-04-01 17:34:44.000000000 -0300
@@ -54,10 +54,9 @@
 It uses the Translate Toolkit to get access to translation files and therefore
 can edit a variety of files (including PO and XLIFF files)."""
 
-INSTALL_CONFIG_DIR = '/etc/pootle'
+INSTALL_CONFIG_DIR = 'etc/pootle'
 INSTALL_DATA_DIR = 'share/pootle'
-INSTALL_DOC_DIR = 'share/doc/pootle'
-INSTALL_WORKING_DIR = '/var/lib/pootle'
+INSTALL_WORKING_DIR = '/var/db/pootle'
 
 ###############################################################################
 # HELPER FUNCTIONS
@@ -65,8 +64,7 @@
 
 def collect_options():
     data_files = [
-        (INSTALL_CONFIG_DIR, ['localsettings.py']),
-        (INSTALL_DOC_DIR, ['wsgi.py', 'ChangeLog', 'COPYING', 'README', 'INSTALL']),
+        (INSTALL_CONFIG_DIR, ['localsettings.py.sample']),
         (INSTALL_WORKING_DIR + '/dbs', []) # Create the empty "dbs" dir
     ] + list_tree(INSTALL_DATA_DIR, 'templates') + list_tree(INSTALL_DATA_DIR, 'html') + \
         list_tree(INSTALL_WORKING_DIR, 'po') + list_tree(INSTALL_DATA_DIR, 'mo')
