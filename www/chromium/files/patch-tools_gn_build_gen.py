--- tools/gn/build/gen.py.orig	2018-12-12 23:06:54.000000000 +0100
+++ tools/gn/build/gen.py	2018-12-15 23:20:32.529540000 +0100
@@ -39,10 +39,12 @@
       self._platform = 'aix'
     elif self._platform.startswith('fuchsia'):
       self._platform = 'fuchsia'
+    elif self._platform.lower().startswith('freebsd'):
+      self._platform = 'bsd'
 
   @staticmethod
   def known_platforms():
-    return ['linux', 'darwin', 'msvc', 'aix', 'fuchsia']
+    return ['linux', 'darwin', 'msvc', 'aix', 'fuchsia', 'bsd']
 
   def platform(self):
     return self._platform
@@ -65,8 +67,11 @@
   def is_aix(self):
     return self._platform == 'aix'
 
+  def is_bsd(self):
+    return self._platform == 'bsd'
+
   def is_posix(self):
-    return self._platform in ['linux', 'darwin', 'aix']
+    return self._platform in ['linux', 'darwin', 'aix', 'bsd']
 
 
 def main(argv):
@@ -168,6 +173,7 @@
       'darwin': 'build_mac.ninja.template',
       'linux': 'build_linux.ninja.template',
       'aix': 'build_aix.ninja.template',
+      'bsd': 'build_linux.ninja.template'
   }[platform.platform()])
 
   with open(template_filename) as f:
@@ -327,7 +333,11 @@
     elif platform.is_aix():
       cflags_cc.append('-maix64')
       ldflags.extend(['-maix64', '-pthread'])
-
+    elif platform.is_bsd():
+      cflags.extend(['-Wno-deprecated-register', '-Wno-parentheses-equality'])
+      ldflags.extend(['-pthread'])
+      libs.extend(['-lexecinfo', '-lkvm'])
+      include_dirs += ['/usr/local/include']
     if options.use_lto:
       cflags.extend(['-flto', '-fwhole-program-vtables'])
       ldflags.extend(['-flto', '-fwhole-program-vtables'])
