--- ./setup.py.orig	2012-06-17 22:22:27.000000000 +1000
+++ ./setup.py	2012-06-17 22:22:42.000000000 +1000
@@ -79,6 +79,7 @@
               'Topic :: Internet :: WWW/HTTP',
               'License :: OSI Approved :: MIT License',
           ],
+          zip_safe=False,
           ext_modules = [Extension('sendfile',
                                    sources=['sendfilemodule.c'],
                                    libraries=libraries)],
