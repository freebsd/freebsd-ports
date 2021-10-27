--- setup.py.orig	2021-10-08 09:21:53 UTC
+++ setup.py
@@ -48,7 +48,7 @@ DEPENDENCIES = [
     'azure-cli-telemetry==1.0.6.*',
     'azure-mgmt-core>=1.2.0,<1.3.0',     # the preview version of azure-mgmt-core is 1.3.0b1, it cannot fit azure-core >=1.14.0
     'cryptography',
-    'humanfriendly>=4.7,<10.0',
+    'humanfriendly>=4.7,<11.0',
     'jmespath',
     'knack~=0.8.2',
     'msal>=1.10.0,<2.0.0',
