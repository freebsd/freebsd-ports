--- setup.py.orig	2009-05-27 17:43:25.000000000 +1000
+++ setup.py	2009-05-27 17:45:52.000000000 +1000
@@ -9,4 +9,5 @@
       author='Google Inc.',
       author_email='opensource@google.com',
       url='http://code.google.com/p/sitemap-generators/',
+      py_modules = [ 'sitemap_gen' ]
      )
