--- tools/gn/build/gen.py.orig	2021-04-14 18:49:10 UTC
+++ tools/gn/build/gen.py
@@ -90,6 +90,9 @@ class Platform(object):
   def is_solaris(self):
     return self._platform == 'solaris'
 
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'haiku', 'solaris', 'msys', 'netbsd']
 
@@ -405,6 +408,11 @@ def WriteGNNinja(path, platform, host, options):
     elif platform.is_haiku():
       cflags.append('-fPIC')
       cflags.extend(['-D_BSD_SOURCE'])
+    elif platform.is_freebsd():
+      cflags.extend(['-Wno-deprecated-register', '-Wno-parentheses-equality'])
+      ldflags.extend(['-pthread'])
+      libs.extend(['-lexecinfo', '-lkvm', '-lutil'])
+      include_dirs += ['/usr/local/include']
 
     if platform.is_posix() and not platform.is_haiku():
       ldflags.append('-pthread')
