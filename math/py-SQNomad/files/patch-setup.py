-- Use numpy.get_include() to find NumPy's C headers instead of building
-- the path manually, because NumPy >= 2.0 moved its C API headers from
-- numpy/core/include to numpy/_core/include, breaking the previous
-- hardcoded path.
-- Also enable the FreeBSD platform check that was missing so the C++14
-- flag is applied on FreeBSD as well as Linux/macOS.

--- setup.py.orig	2021-03-29 23:39:12 UTC
+++ setup.py
@@ -52,10 +52,10 @@ class my_build_extension(_build_ext):
 
         # adding numpy late to allow setup to install it in the build env
         import numpy
-        ext.extra_compile_args += ['-I'+os.path.join(numpy.__path__[0], 'core/include/numpy')]
+        ext.extra_compile_args += ['-I'+numpy.get_include(), '-I'+os.path.join(numpy.get_include(), 'numpy')]
 
         # force C++14
-        if 'linux' in sys.platform or 'darwin' in sys.platform:
+        if 'linux' in sys.platform or 'freebsd' in sys.platform or 'darwin' in sys.platform:
             ext.extra_compile_args += ['-std=c++14']
         elif 'win32' in sys.platform:
           # also define DLL_EXPORTS for sgtelib and NOMAD::Clock
