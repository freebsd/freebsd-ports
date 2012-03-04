--- setup.py.orig	2012-01-30 00:14:40.000000000 +0000
+++ setup.py	2012-02-07 13:49:58.000000000 +0000
@@ -44,10 +44,10 @@
       author_email='andrey.petrov@shazow.net',
       url='http://urllib3.readthedocs.org/',
       license='MIT',
-      packages=['urllib3', 'dummyserver', 'urllib3.packages',
+      packages=['urllib3', 'urllib3.packages',
                 'urllib3.packages.ssl_match_hostname', 'urllib3.packages.mimetools_choose_boundary',
                 ],
       requires=requirements,
-      tests_require=tests_requirements,
-      test_suite='test',
+      #tests_require=tests_requirements,
+      #test_suite='test',
       )
