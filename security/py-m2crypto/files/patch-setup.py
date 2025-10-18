--- setup.py.orig	2025-10-01 23:07:58 UTC
+++ setup.py
@@ -168,9 +168,6 @@ class _M2CryptoBuildExt(build_ext.build_ext):
         log.debug("self.openssl_path = %s", self.openssl_path)
         log.debug("self.bundledlls = %s", self.bundledlls)
 
-        # swig seems to need the default header file directories
-        self.swig_opts.extend(["-I%s" % i for i in _get_additional_includes()])
-
         log.debug("self.include_dirs = %s", self.include_dirs)
         log.debug("self.library_dirs = %s", self.library_dirs)
 
@@ -237,6 +234,9 @@ class _M2CryptoBuildExt(build_ext.build_ext):
                         f"gcc -E ended with return code {pid.returncode}"
                     )
 
+        # swig seems to need the default header file directories
+        self.swig_opts.extend(["-I%s" % i for i in _get_additional_includes()])
+
         # Some Linux distributor has added the following line in
         # /usr/include/openssl/opensslconf.h:
         #
@@ -257,7 +257,7 @@ class _M2CryptoBuildExt(build_ext.build_ext):
         if platform.system() == "Darwin":
             self.swig_opts.append("-cpperraswarn")
 
-        self.swig_opts.append("-includeall")
+        #self.swig_opts.append("-includeall")
         self.swig_opts.append("-builtin")
 
         build_dir = os.path.join(self.build_lib, "M2Crypto")
