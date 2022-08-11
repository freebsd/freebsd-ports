--- scripts/mk_util.py.orig	2022-05-05 00:16:30 UTC
+++ scripts/mk_util.py
@@ -2543,8 +2543,8 @@ def mk_config():
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
