--- setup.py.orig	2021-09-03 06:33:24 UTC
+++ setup.py
@@ -49,7 +49,7 @@ DEPENDENCIES = [
     'azure-common~=1.1',
     'azure-mgmt-core>=1.2.0,<1.3.0',     # the preview version of azure-mgmt-core is 1.3.0b1, it cannot fit azure-core >=1.14.0
     'cryptography>=3.2,<3.4',
-    'humanfriendly>=4.7,<10.0',
+    'humanfriendly>=4.7,<11.0',
     'jmespath',
     'knack~=0.8.2',
     'msal>=1.10.0,<2.0.0',
