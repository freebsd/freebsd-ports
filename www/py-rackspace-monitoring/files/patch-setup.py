--- setup.py.orig	2018-08-13 13:22:29 UTC
+++ setup.py
@@ -171,7 +171,7 @@ setup(
     description='Client library for Rackspace Cloud Monitoring',
     author='Rackspace, Inc.',
     author_email='monitoring@rackspace.com',
-    install_requires=['apache-libcloud >= 0.17,<2.0',
+    install_requires=['apache-libcloud >= 0.17',
                       'backports.ssl_match_hostname'],
     packages=[
         'rackspace_monitoring',
