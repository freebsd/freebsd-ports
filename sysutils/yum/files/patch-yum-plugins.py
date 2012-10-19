--- yum/plugins.py.orig	2010-07-06 17:46:39.000000000 +0200
+++ yum/plugins.py	2010-08-22 13:36:48.000000000 +0200
@@ -135,7 +135,7 @@
             files. Defaults to "/etc/yum/pluginconf.d".
         '''
         if not pluginconfpath:
-            pluginconfpath = ['/etc/yum/pluginconf.d']
+            pluginconfpath = ['@PREFIX@/etc/yum/pluginconf.d']
 
         self.searchpath = searchpath
         self.pluginconfpath = pluginconfpath
