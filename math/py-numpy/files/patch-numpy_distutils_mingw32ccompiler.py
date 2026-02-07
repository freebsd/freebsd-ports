--- numpy/distutils/mingw32ccompiler.py.orig	2024-02-05 21:17:48 UTC
+++ numpy/distutils/mingw32ccompiler.py
@@ -24,7 +24,13 @@ from distutils.unixccompiler import UnixCCompiler
 
 import distutils.cygwinccompiler
 from distutils.unixccompiler import UnixCCompiler
-from distutils.msvccompiler import get_build_version as get_build_msvc_version
+
+try:
+    from distutils.msvccompiler import get_build_version as get_build_msvc_version
+except ImportError:
+    def get_build_msvc_version():
+        return None
+
 from distutils.errors import UnknownFileError
 from numpy.distutils.misc_util import (msvc_runtime_library,
                                        msvc_runtime_version,
