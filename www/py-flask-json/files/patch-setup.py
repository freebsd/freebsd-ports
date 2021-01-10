--- setup.py.orig	2019-08-23 17:34:24 UTC
+++ setup.py
@@ -43,6 +43,5 @@ setup(
         'Topic :: Internet :: WWW/HTTP :: Dynamic Content',
         'Topic :: Software Development :: Libraries :: Python Modules'
     ],
-    setup_requires=['pytest-runner'],
     tests_require=['pytest', 'pytest-cov']
 )
