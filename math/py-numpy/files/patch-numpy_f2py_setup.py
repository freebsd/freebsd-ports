--- numpy/f2py/setup.py.orig	Tue Oct  3 00:35:22 2006
+++ numpy/f2py/setup.py	Sat Dec  9 22:51:47 2006
@@ -34,8 +34,7 @@
     config.add_data_dir('docs')
 
     config.add_data_files('src/fortranobject.c',
-                          'src/fortranobject.h',
-                          'f2py.1'
+                          'src/fortranobject.h'
                           )
 
     config.make_svn_version_py()
