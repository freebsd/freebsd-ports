--- setup.py.orig	2020-12-08 18:29:38 UTC
+++ setup.py
@@ -151,9 +151,6 @@ class _M2CryptoBuildExt(build_ext.build_ext):
         if sys.version_info[:1] >= (3,):
             self.swig_opts.append('-py3')
 
-        # swig seems to need the default header file directories
-        self.swig_opts.extend(['-I%s' % i for i in _get_additional_includes()])
-
         log.debug('self.include_dirs = %s', self.include_dirs)
         log.debug('self.library_dirs = %s', self.library_dirs)
 
@@ -186,6 +183,9 @@ class _M2CryptoBuildExt(build_ext.build_ext):
 
         self.swig_opts.extend(['-I%s' % i for i in self.include_dirs])
 
+        # swig seems to need the default header file directories
+        self.swig_opts.extend(['-I%s' % i for i in _get_additional_includes()])
+
         # Some Linux distributor has added the following line in
         # /usr/include/openssl/opensslconf.h:
         #
@@ -204,7 +204,7 @@ class _M2CryptoBuildExt(build_ext.build_ext):
             self.swig_opts.append(
                 '-I' + os.path.join(openssl_include_dir, 'openssl'))
 
-        self.swig_opts.append('-includeall')
+        #self.swig_opts.append('-includeall')
         self.swig_opts.append('-modern')
         self.swig_opts.append('-builtin')
 
