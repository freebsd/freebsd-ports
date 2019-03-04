--- setup.py.orig	2016-02-07 23:17:13 UTC
+++ setup.py
@@ -45,9 +45,7 @@ setup(
     license='MIT License',
     keywords='requests authentication amazon web services aws s3 REST',
     install_requires=['requests'],
-    package_data={'requests_aws4auth': ['test/requests_aws4auth_test.py',
-                                        '../README.rst', '../LICENSE',
-                                        '../NOTICE', '../HISTORY.rst']},
+    package_data={'requests_aws4auth': ['test/requests_aws4auth_test.py']},
     classifiers=[
         'Development Status :: 3 - Alpha',
         'Intended Audience :: Developers',
