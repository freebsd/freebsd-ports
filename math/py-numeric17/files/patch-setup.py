--- setup.py.orig	Tue Sep 12 22:27:29 2000
+++ setup.py	Thu Sep 21 17:17:55 2000
@@ -27,6 +27,9 @@
 LAPACKLIBDIR = None  
 # places to look and what to look for
 POSSIBLE_DIRECTORIES = ['/usr/local/lib', '/usr/lib', 'lapack_lite']
+# add sys.prefix + '/lib', on the assumption that python was
+# installed in the same directory as all other local software
+POSSIBLE_DIRECTORIES.append(sys.prefix + '/lib')
 if sys.platform == 'win32':
     BLASNAMES = ['blas.lib']
     LAPACKNAMES = ['lapack.lib']
