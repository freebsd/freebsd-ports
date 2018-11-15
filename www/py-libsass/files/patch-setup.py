--- setup.py.orig	2018-11-13 19:39:18 UTC
+++ setup.py
@@ -37,7 +37,7 @@ def _maybe_clang(flags):
         compiler.linker_so[0] = os.environ['CXX']
         return compiler
     distutils.sysconfig.customize_compiler = customize_compiler
-    flags[:] = ['-c', '-O3'] + flags + ['-stdlib=libc++']
+    flags[:] = ['-c'] + flags
 
 
 def _maybe_macos(flags):
@@ -54,7 +54,7 @@ def _maybe_macos(flags):
 if sys.platform == 'win32':
     extra_link_args = []
 elif platform.system() in {'Darwin', 'FreeBSD'}:
-    extra_link_args = ['-fPIC', '-lc++']
+    extra_link_args = ['-fPIC', '-lstdc++']
 else:
     extra_link_args = ['-fPIC', '-lstdc++']
 
