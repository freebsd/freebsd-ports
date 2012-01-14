--- setup.py.orig	2012-01-07 22:23:02.000000000 +0100
+++ setup.py	2012-01-09 19:08:23.000000000 +0100
@@ -49,6 +49,6 @@
       license='MIT',
       packages=['urllib3', 'dummyserver', 'urllib3.packages', 'urllib3.packages.ssl_match_hostname'],
       requires=requirements,
-      tests_require=tests_requirements,
-      test_suite='test',
+      #tests_require=tests_requirements,
+      #test_suite='test',
       )
