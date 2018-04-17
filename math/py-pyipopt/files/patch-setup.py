--- setup.py.orig	2018-04-17 07:40:56 UTC
+++ setup.py
@@ -48,11 +48,11 @@ pyipopt_extension = Extension(
         #extra_link_args=['-Wl,--rpath','-Wl,'+ IPOPT_LIB],
         library_dirs=[IPOPT_LIB],
         libraries=[
-            'ipopt', 'coinblas',
+            'ipopt',
             #'coinhsl',
             'coinmumps',
             'coinmetis',
-            'coinlapack','dl','m',
+            'm',
             ],
         include_dirs=[numpy_include, IPOPT_INC],
         )
