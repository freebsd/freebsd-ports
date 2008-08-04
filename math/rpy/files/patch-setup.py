--- setup.py.orig	2008-07-29 22:53:21.000000000 +0200
+++ setup.py	2008-07-29 22:54:04.000000000 +0200
@@ -159,8 +159,8 @@
         source_files = source_files + ["src/setenv.c"]
     else: # unix-like systems, this is known to work for Linux and Solaris
         include_dirs = [ os.path.join(RHOME.strip(), 'include'), 
-                         'src', '/usr/share/R/include' ]
-        libraries=['R','Rlapack']
+                         'src', '%%LOCALBASE%%/lib/R/include' ]
+        libraries=['R','R']
         library_dirs = r_libs
         runtime_libs = r_libs
         extra_compile_args=["-shared"]
