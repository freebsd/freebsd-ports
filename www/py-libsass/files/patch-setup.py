--- setup.py.orig	2018-09-16 19:57:43 UTC
+++ setup.py
@@ -37,7 +37,7 @@ def _maybe_clang(flags):
         compiler.linker_so[0] = os.environ['CXX']
         return compiler
     distutils.sysconfig.customize_compiler = customize_compiler
-    flags[:] = ['-c', '-O3'] + flags + ['-stdlib=libc++']
+    flags[:] = ['-c'] + flags
 
 
 def _maybe_macos(flags):
@@ -59,7 +59,7 @@ if system_sass:
     _maybe_macos(flags)
 
     if platform.system() == 'FreeBSD':
-        link_flags = ['-fPIC', '-lc++']
+        link_flags = ['-fPIC']
     else:
         link_flags = ['-fPIC', '-lstdc++']
     libraries = ['sass']
@@ -173,7 +173,7 @@ else:
                         f.write(cencode_body)
 
         if platform.system() == 'FreeBSD':
-            link_flags = ['-fPIC', '-lc++']
+            link_flags = ['-fPIC']
         else:
             link_flags = ['-fPIC', '-lstdc++']
 
