--- setup.py.orig	2021-05-21 16:58:29 UTC
+++ setup.py
@@ -45,9 +45,7 @@ setup(
     keywords='requests authentication amazon web services aws s3 REST',
     install_requires=['requests', 'six'],
     packages=['requests_aws4auth'],
-    package_data={'requests_aws4auth': ['test/requests_aws4auth_test.py',
-                                        '../README.md', '../LICENSE',
-                                        '../HISTORY.md']},
+    package_data={'requests_aws4auth': ['test/requests_aws4auth_test.py']},
     classifiers=[
         'Development Status :: 5 - Production/Stable',
         'Intended Audience :: Developers',
