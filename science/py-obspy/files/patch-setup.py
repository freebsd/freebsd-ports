--- setup.py.orig	2012-12-17 14:04:38.000000000 +0000
+++ setup.py	2013-05-16 15:35:53.000000000 +0000
@@ -362,8 +362,8 @@
             # otherwise we just use the original compile method
             UnixCCompiler.linker_so = None
             return self._original_compile(obj, src, *args, **kwargs)
-        UnixCCompiler.linker_so = ["gfortran"]
-        self.compiler_so = ["gfortran"]
+        UnixCCompiler.linker_so = ["FC"]
+        self.compiler_so = ["FC"]
         cc_args = ['-c', '-fno-underscoring']
         if sys.platform == 'darwin':
             self.compiler_so = _darwin_compiler_fixup(self.compiler_so,
