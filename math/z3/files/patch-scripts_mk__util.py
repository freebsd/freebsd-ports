--- scripts/mk_util.py.orig	2019-09-19 23:43:06 UTC
+++ scripts/mk_util.py
@@ -2508,8 +2508,8 @@ def mk_config():
         check_ar()
         CXX = find_cxx_compiler()
         CC  = find_c_compiler()
-        SLIBEXTRAFLAGS = ''
-#       SLIBEXTRAFLAGS = '%s -Wl,-soname,libz3.so.0' % LDFLAGS
+#       SLIBEXTRAFLAGS = ''
+        SLIBEXTRAFLAGS = '%s -Wl,-soname,libz3.so.0' % LDFLAGS
         EXE_EXT = ''
         LIB_EXT = '.a'
         if GPROF:
