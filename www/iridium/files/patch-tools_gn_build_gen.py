--- tools/gn/build/gen.py.orig	2020-03-16 18:48:21 UTC
+++ tools/gn/build/gen.py
@@ -73,6 +73,9 @@ class Platform(object):
   def is_haiku(self):
     return self._platform == 'haiku'
 
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd', 'haiku']
 
@@ -351,6 +354,11 @@ def WriteGNNinja(path, platform, host, options):
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
