--- scripts/mk_util.py.orig	2017-12-18 14:18:30 UTC
+++ scripts/mk_util.py
@@ -49,7 +49,7 @@ C_COMPILERS=['gcc', 'clang']
 CSC_COMPILERS=['csc', 'mcs']
 JAVAC=None
 JAR=None
-PYTHON_PACKAGE_DIR=distutils.sysconfig.get_python_lib()
+PYTHON_PACKAGE_DIR=distutils.sysconfig.get_python_lib(prefix=getenv("PREFIX", None))
 BUILD_DIR='build'
 REV_BUILD_DIR='..'
 SRC_DIR='src'
@@ -2441,7 +2441,7 @@ def mk_config():
         check_ar()
         CXX = find_cxx_compiler()
         CC  = find_c_compiler()
-        SLIBEXTRAFLAGS = ''
+        SLIBEXTRAFLAGS = '%s -Wl,-soname,libz3.so.0' % LDFLAGS
         EXE_EXT = ''
         LIB_EXT = '.a'
         if GPROF:
