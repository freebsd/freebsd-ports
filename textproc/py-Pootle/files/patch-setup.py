--- setup.py.orig	2010-09-07 16:54:40.000000000 -0500
+++ setup.py	2010-09-07 16:54:53.000000000 -0500
@@ -54,7 +54,7 @@
 It uses the Translate Toolkit to get access to translation files and therefore
 can edit a variety of files (including PO and XLIFF files)."""
 
-INSTALL_CONFIG_DIR = '/etc/pootle'
+INSTALL_CONFIG_DIR = 'etc/pootle'
 INSTALL_DATA_DIR = 'share/pootle'
 INSTALL_DOC_DIR = 'share/doc/pootle'
 INSTALL_WORKING_DIR = '/var/lib/pootle'
