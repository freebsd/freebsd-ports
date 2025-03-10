--- setup.py.orig	2024-10-09 22:15:33 UTC
+++ setup.py
@@ -164,11 +164,6 @@ class _M2CryptoBuildExt(build_ext.build_ext):
         log.debug('self.openssl_path = %s', self.openssl_path)
         log.debug('self.bundledlls = %s', self.bundledlls)
 
-        # swig seems to need the default header file directories
-        self.swig_opts.extend(
-            ['-I%s' % i for i in _get_additional_includes()]
-        )
-
         log.debug('self.include_dirs = %s', self.include_dirs)
         log.debug('self.library_dirs = %s', self.library_dirs)
 
@@ -238,6 +233,11 @@ class _M2CryptoBuildExt(build_ext.build_ext):
                         f"gcc -E ended with return code {pid.returncode}"
                     )
 
+        # swig seems to need the default header file directories
+        self.swig_opts.extend(
+            ['-I%s' % i for i in _get_additional_includes()]
+        )
+
         # Some Linux distributor has added the following line in
         # /usr/include/openssl/opensslconf.h:
         #
@@ -257,7 +257,7 @@ class _M2CryptoBuildExt(build_ext.build_ext):
                 '-I' + os.path.join(openssl_include_dir, 'openssl')
             )
 
-        self.swig_opts.append('-includeall')
+        #self.swig_opts.append('-includeall')
         self.swig_opts.append('-builtin')
 
         build_dir = os.path.join(self.build_lib, 'M2Crypto')
