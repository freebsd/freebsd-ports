--- setup.py.orig	2024-01-29 18:20:51 UTC
+++ setup.py
@@ -132,9 +132,6 @@ class _M2CryptoBuildExt(build_ext.build_ext):
         log.debug('self.openssl_path = %s', self.openssl_path)
         log.debug('self.bundledlls = %s', self.bundledlls)
 
-        # swig seems to need the default header file directories
-        self.swig_opts.extend(['-I%s' % i for i in _get_additional_includes()])
-
         log.debug('self.include_dirs = %s', self.include_dirs)
         log.debug('self.library_dirs = %s', self.library_dirs)
 
@@ -169,6 +166,9 @@ class _M2CryptoBuildExt(build_ext.build_ext):
 
         self.swig_opts.extend(['-I%s' % i for i in self.include_dirs])
 
+        # swig seems to need the default header file directories
+        self.swig_opts.extend(['-I%s' % i for i in _get_additional_includes()])
+
         # Some Linux distributor has added the following line in
         # /usr/include/openssl/opensslconf.h:
         #
@@ -187,7 +187,7 @@ class _M2CryptoBuildExt(build_ext.build_ext):
             self.swig_opts.append(
                 '-I' + os.path.join(openssl_include_dir, 'openssl'))
 
-        self.swig_opts.append('-includeall')
+        #self.swig_opts.append('-includeall')
         self.swig_opts.append('-builtin')
 
         build_dir = os.path.join(self.build_lib, 'M2Crypto')
