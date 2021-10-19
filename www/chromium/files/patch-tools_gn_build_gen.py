--- tools/gn/build/gen.py.orig	2021-09-24 04:34:58 UTC
+++ tools/gn/build/gen.py
@@ -91,6 +91,9 @@ class Platform(object):
   def is_solaris(self):
     return self._platform == 'solaris'
 
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'haiku', 'solaris', 'msys', 'netbsd']
 
@@ -429,6 +432,11 @@ def WriteGNNinja(path, platform, host, options):
       cflags.append('-Wno-unused-function')
       cflags.append('-D_OPEN_SYS_FILE_EXT')
       cflags.append('-DPATH_MAX=1024')
+    elif platform.is_freebsd():
+      cflags.extend(['-Wno-deprecated-register', '-Wno-parentheses-equality'])
+      ldflags.extend(['-pthread'])
+      libs.extend(['-lexecinfo', '-lkvm', '-lutil'])
+      include_dirs += ['/usr/local/include']
 
     if platform.is_posix() and not platform.is_haiku():
       ldflags.append('-pthread')
