--- tools/gn/build/gen.py.orig	2019-02-06 23:16:22.000000000 +0100
+++ tools/gn/build/gen.py	2019-02-08 18:27:37.227094000 +0100
@@ -44,7 +44,7 @@
 
   @staticmethod
   def known_platforms():
-    return ['linux', 'darwin', 'msvc', 'aix', 'fuchsia']
+    return ['linux', 'darwin', 'msvc', 'aix', 'fuchsia', 'freebsd']
 
   def platform(self):
     return self._platform
@@ -67,6 +67,9 @@
   def is_aix(self):
     return self._platform == 'aix'
 
+  def is_freebsd(self):
+    return self._platform == 'freebsd'
+
   def is_posix(self):
     return self._platform in ['linux', 'freebsd', 'darwin', 'aix']
 
@@ -332,6 +335,11 @@
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
