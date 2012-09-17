--- setup.py.orig	2012-09-16 18:44:32.000000000 +0800
+++ setup.py	2012-09-16 18:45:02.000000000 +0800
@@ -55,7 +55,7 @@
     UnixCCompiler.linker_so = ["gfortran"]
 
     def _compile(self, obj, src, *args, **kwargs):  # @UnusedVariable
-            self.compiler_so = ["gfortran"]
+            self.compiler_so = [os.environ.get("F77")]
             cc_args = ['-c', '-fno-underscoring']
             if sys.platform == 'darwin':
                 self.compiler_so = _darwin_compiler_fixup(self.compiler_so,
