--- numpy/f2py/setup.py.orig	2015-08-11 17:03:43 UTC
+++ numpy/f2py/setup.py
@@ -55,7 +55,7 @@ def configuration(parent_package='', top
     config.make_svn_version_py()
 
     def generate_f2py_py(build_dir):
-        f2py_exe = 'f2py' + os.path.basename(sys.executable)[6:]
+        f2py_exe = 'f2py'
         if f2py_exe[-4:] == '.exe':
             f2py_exe = f2py_exe[:-4] + '.py'
         if 'bdist_wininst' in sys.argv and f2py_exe[-3:] != '.py':
