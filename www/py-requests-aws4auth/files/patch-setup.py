--- setup.py.orig	2020-06-06 19:44:57 UTC
+++ setup.py
@@ -45,9 +45,7 @@ setup(
     keywords='requests authentication amazon web services aws s3 REST',
     install_requires=['requests'],
     packages=['requests_aws4auth'],
-    package_data={'requests_aws4auth': ['test/requests_aws4auth_test.py',
-                                        '../README.md', '../LICENSE',
-                                        '../HISTORY.md']},
+    package_data={'requests_aws4auth': ['test/requests_aws4auth_test.py']},
     classifiers=[
         'Development Status :: 3 - Alpha',
         'Intended Audience :: Developers',
