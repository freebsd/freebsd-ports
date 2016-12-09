--- scripts/mk_util.py.orig	2016-11-07 22:02:30 UTC
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
@@ -2391,7 +2391,7 @@ def mk_config():
         check_ar()
         CXX = find_cxx_compiler()
         CC  = find_c_compiler()
-        SLIBEXTRAFLAGS = ''
+        SLIBEXTRAFLAGS = LDFLAGS
         if GPROF:
             CXXFLAGS = '%s -pg' % CXXFLAGS
             LDFLAGS  = '%s -pg' % LDFLAGS
