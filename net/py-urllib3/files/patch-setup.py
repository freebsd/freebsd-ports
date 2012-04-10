--- setup.py.orig	2012-01-30 01:14:40.000000000 +0100
+++ setup.py	2012-03-26 17:32:14.000000000 +0200
@@ -44,7 +44,7 @@
       author_email='andrey.petrov@shazow.net',
       url='http://urllib3.readthedocs.org/',
       license='MIT',
-      packages=['urllib3', 'dummyserver', 'urllib3.packages',
+      packages=['urllib3', 'urllib3.packages',
                 'urllib3.packages.ssl_match_hostname', 'urllib3.packages.mimetools_choose_boundary',
                 ],
       requires=requirements,
