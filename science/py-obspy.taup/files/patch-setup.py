--- setup.py.orig	2012-01-16 08:34:50.000000000 +0800
+++ setup.py	2012-01-16 08:35:13.000000000 +0800
@@ -53,7 +53,7 @@
     # Monkey patch UnixCCompiler for Unix, Linux and MacOS
     UnixCCompiler.src_extensions.append(".f")
     def _compile(self, obj, src, *args, **kwargs): #@UnusedVariable
-            self.compiler_so = ["gfortran"]
+            self.compiler_so = [os.environ.get("F77")]
             cc_args = ['-c', '-fno-underscoring']
             if sys.platform == 'darwin':
                 self.compiler_so = _darwin_compiler_fixup(self.compiler_so,
