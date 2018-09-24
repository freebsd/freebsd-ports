--- setup.py.orig	2018-04-29 18:47:25 UTC
+++ setup.py
@@ -196,7 +196,7 @@ class _M2CryptoBuildExt(build_ext.build_
 
         # swig seems to need the default header file directories
         self.swig_opts.extend(['-I%s' % i for i in _get_additional_includes()])
-        self.swig_opts.append('-includeall')
+        #self.swig_opts.append('-includeall')
         self.swig_opts.append('-modern')
         self.swig_opts.append('-builtin')
 
