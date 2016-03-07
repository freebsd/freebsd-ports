--- setup.py.orig	2016-03-07 05:34:43 UTC
+++ setup.py
@@ -171,7 +171,7 @@ setup(
     description='Client library for Rackspace Cloud Monitoring',
     author='Rackspace, Inc.',
     author_email='monitoring@rackspace.com',
-    install_requires=['apache-libcloud >= 0.14, <0.16'],
+    install_requires=['apache-libcloud >= 0.14'],
     packages=[
         'rackspace_monitoring',
         'rackspace_monitoring.drivers',
