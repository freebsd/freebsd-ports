--- setup.py.orig	2017-11-16 05:28:26 UTC
+++ setup.py
@@ -37,7 +37,7 @@ def _maybe_clang(flags):
         compiler.linker_so[0] = os.environ['CXX']
         return compiler
     distutils.sysconfig.customize_compiler = customize_compiler
-    flags[:] = ['-c', '-O3'] + flags + ['-stdlib=libc++']
+    flags[:] = ['-c'] + flags + ['-stdlib=libc++']
 
 
 def _maybe_macos(flags):
