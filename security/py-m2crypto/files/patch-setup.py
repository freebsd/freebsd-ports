--- setup.py.orig	2020-12-08 18:29:38 UTC
+++ setup.py
@@ -204,7 +204,7 @@ class _M2CryptoBuildExt(build_ext.build_ext):
             self.swig_opts.append(
                 '-I' + os.path.join(openssl_include_dir, 'openssl'))
 
-        self.swig_opts.append('-includeall')
+        #self.swig_opts.append('-includeall')
         self.swig_opts.append('-modern')
         self.swig_opts.append('-builtin')
 
