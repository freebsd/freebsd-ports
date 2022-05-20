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
@@ -2632,7 +2632,7 @@ def mk_config():
         if is64():
             if not sysname.startswith('CYGWIN') and not sysname.startswith('MSYS') and not sysname.startswith('MINGW'):
                 CXXFLAGS     = '%s -fPIC' % CXXFLAGS
-            if sysname == 'Linux':
+            if sysname == 'Linux' or sysname == 'FreeBSD':
                 CPPFLAGS = '%s -D_USE_THREAD_LOCAL' % CPPFLAGS
         elif not LINUX_X64:
             CXXFLAGS     = '%s -m32' % CXXFLAGS
