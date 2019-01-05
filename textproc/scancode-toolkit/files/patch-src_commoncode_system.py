--- src/commoncode/system.py.orig	2018-05-08 13:54:52 UTC
+++ src/commoncode/system.py
@@ -46,6 +46,8 @@ def os_arch():
         os = 'win'
     elif 'darwin' in sys_platform:
         os = 'mac'
+    elif 'freebsd' in sys_platform:
+        os = 'freebsd'
     else:
         raise Exception('Unsupported OS/platform %r' % sys_platform)
     return os, arch
@@ -84,7 +86,8 @@ current_os, current_arch = os_arch()
 on_windows = current_os == 'win'
 on_mac = current_os == 'mac'
 on_linux = current_os == 'linux'
-on_posix = not on_windows and (on_mac or on_linux)
+on_freebsd = current_os == 'freebsd'
+on_posix = not on_windows and (on_mac or on_linux or on_freebsd)
 
 current_os_arch = '%(current_os)s-%(current_arch)s' % locals()
 noarch = 'noarch'
@@ -97,7 +100,7 @@ if on_windows:
     lib_ext = '.dll'
 if on_mac:
     lib_ext = '.dylib'
-if on_linux:
+if on_linux or on_freebsd:
     lib_ext = '.so'
 
 #
