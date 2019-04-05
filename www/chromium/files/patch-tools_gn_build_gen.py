--- tools/gn/build/gen.py.orig	2019-03-11 22:12:13 UTC
+++ tools/gn/build/gen.py
@@ -44,7 +44,7 @@ class Platform(object):
 
   @staticmethod
   def known_platforms():
-    return ['linux', 'darwin', 'msvc', 'aix', 'fuchsia']
+    return ['linux', 'darwin', 'msvc', 'aix', 'fuchsia', 'freebsd']
 
   def platform(self):
     return self._platform
@@ -67,6 +67,9 @@ class Platform(object):
   def is_aix(self):
     return self._platform == 'aix'
 
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix']
 
@@ -332,6 +335,11 @@ def WriteGNNinja(path, platform, host, options):
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
