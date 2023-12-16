--- setup.py.orig	2023-11-12 00:10:52 UTC
+++ setup.py
@@ -55,7 +55,7 @@ class my_build_extension(_build_ext):
         ext.extra_compile_args += ['-I'+os.path.join(numpy.__path__[0], 'core/include/numpy')]
 
         # force C++14
-        if 'linux' in sys.platform or 'darwin' in sys.platform:
+        if 'linux' in sys.platform or 'freebsd' in sys.platform or 'darwin' in sys.platform:
             ext.extra_compile_args += ['-std=c++14']
         elif 'win32' in sys.platform:
           # also define DLL_EXPORTS for sgtelib and NOMAD::Clock
