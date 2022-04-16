--- setup.py.orig	2022-02-18 22:52:53 UTC
+++ setup.py
@@ -39,7 +39,7 @@ setup(
     },
     test_suite='tests',
     install_requires=[
-        'lxml<4.7.1',
+        'lxml',
         'isodate>=0.6.1',
         'xmlsec>=1.3.9'
     ],
