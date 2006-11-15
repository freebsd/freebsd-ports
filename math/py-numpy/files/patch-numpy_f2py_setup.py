--- numpy/f2py/setup.py.orig	Sat Sep 23 05:25:27 2006
+++ numpy/f2py/setup.py	Sat Sep 23 05:25:41 2006
@@ -32,8 +32,7 @@
     config.add_data_dir('docs')
 
     config.add_data_files('src/fortranobject.c',
-                          'src/fortranobject.h',
-                          'f2py.1'
+                          'src/fortranobject.h'
                           )
 
     config.make_svn_version_py()
