--- ./setup.py.orig	2013-10-29 15:50:15.741120947 +0200
+++ ./setup.py	2013-10-29 15:51:01.621119992 +0200
@@ -68,6 +68,9 @@
     elif sys.platform == 'darwin':
         COMPILER_SETTINGS['include_dirs'] += ['/opt/local/include']
         COMPILER_SETTINGS['library_dirs'] += ['/opt/local/lib']
+    elif sys.platform.startswith('freebsd'):
+        COMPILER_SETTINGS['include_dirs'] += ['%%LOCALBASE%%/include']
+        COMPILER_SETTINGS['library_dirs'] += ['%%LOCALBASE%%/lib']
     COMPILER_SETTINGS['runtime_library_dirs'] = [op.abspath(x) for x in COMPILER_SETTINGS['library_dirs']]
 
 MODULES =  ['defs','_errors','_objects','_proxy', 'h5fd', 'h5z',
