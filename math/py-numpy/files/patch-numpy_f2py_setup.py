--- numpy/f2py/setup.py.orig	Mon Oct  2 17:08:55 2006
+++ numpy/f2py/setup.py	Mon Jun 11 12:17:13 2007
@@ -34,14 +34,13 @@
     config.add_data_dir('docs')
 
     config.add_data_files('src/fortranobject.c',
-                          'src/fortranobject.h',
-                          'f2py.1'
+                          'src/fortranobject.h'
                           )
 
     config.make_svn_version_py()
 
     def generate_f2py_py(build_dir):
-        f2py_exe = 'f2py'+os.path.basename(sys.executable)[6:]
+        f2py_exe = 'f2py'
         if f2py_exe[-4:]=='.exe':
             f2py_exe = f2py_exe[:-4] + '.py'
         if 'bdist_wininst' in sys.argv and f2py_exe[-3:] != '.py':
