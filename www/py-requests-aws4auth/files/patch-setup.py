--- setup.py.orig	2020-09-29 00:16:05 UTC
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
         'Development Status :: 5 - Production/Stable',
         'Intended Audience :: Developers',
