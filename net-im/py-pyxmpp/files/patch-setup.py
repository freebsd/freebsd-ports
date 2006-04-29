--- ./setup.py.orig	Wed Apr 19 18:58:34 2006
+++ ./setup.py	Wed Apr 19 18:59:59 2006
@@ -26,8 +26,8 @@
         include_dirs = [r'd:\libs\include', r'd:\libs\include\libxml']
         library_dirs = [r'd:\libs\lib']
     else:
-        include_dirs = ['/usr/include/libxml2','/usr/local/include/libxml2']
-        library_dirs = []
+        include_dirs = ['/usr/include/libxml2','/usr/local/include/libxml2','/usr/local/include']
+        library_dirs = ['/usr/local/lib']
     ext_modules = [
         Extension(
             'pyxmpp._xmlextra',
