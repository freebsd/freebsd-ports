--- tools/gn/build/gen.py.orig	2022-02-07 13:39:41 UTC
+++ tools/gn/build/gen.py
@@ -91,6 +91,12 @@ class Platform(object):
   def is_solaris(self):
     return self._platform == 'solaris'
 
+  def is_openbsd(self):
+    return self._platform == 'openbsd'
+
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'haiku', 'solaris', 'msys', 'netbsd']
 
@@ -228,7 +234,7 @@ def WriteGenericNinja(path, static_libraries, executab
       'linux': 'build_linux.ninja.template',
       'freebsd': 'build_linux.ninja.template',
       'aix': 'build_aix.ninja.template',
-      'openbsd': 'build_openbsd.ninja.template',
+      'openbsd': 'build_linux.ninja.template',
       'haiku': 'build_haiku.ninja.template',
       'solaris': 'build_linux.ninja.template',
       'netbsd': 'build_linux.ninja.template',
@@ -432,6 +438,9 @@ def WriteGNNinja(path, platform, host, options):
 
     if platform.is_posix() and not platform.is_haiku():
       ldflags.append('-pthread')
+
+    if platform.is_openbsd():
+      libs.append('-lkvm')
 
     if platform.is_mingw() or platform.is_msys():
       cflags.extend(['-DUNICODE',
