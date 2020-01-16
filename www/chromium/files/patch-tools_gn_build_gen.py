--- tools/gn/build/gen.py.orig	2019-12-16 21:58:04 UTC
+++ tools/gn/build/gen.py
@@ -69,6 +69,9 @@ class Platform(object):
   def is_aix(self):
     return self._platform == 'aix'
 
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix', 'openbsd']
 
@@ -341,6 +344,11 @@ def WriteGNNinja(path, platform, host, options):
     elif platform.is_aix():
       cflags_cc.append('-maix64')
       ldflags.append('-maix64')
+    elif platform.is_freebsd():
+      cflags.extend(['-Wno-deprecated-register', '-Wno-parentheses-equality'])
+      ldflags.extend(['-pthread'])
+      libs.extend(['-lexecinfo', '-lkvm', '-lutil'])
+      include_dirs += ['/usr/local/include']
 
     if platform.is_posix():
       ldflags.append('-pthread')
