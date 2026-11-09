--- setup.py.orig	2026-09-29 06:56:43 UTC
+++ setup.py
@@ -44,9 +44,9 @@ DEPENDENCIES = [
 ]
 
 DEPENDENCIES = [
-    'argcomplete~=3.5.2',
+    'argcomplete>=3.5.2',
     'azure-cli-telemetry==1.1.0.*',
-    'azure-core~=1.39.0',
+    'azure-core>=1.39.0',
     'azure-mgmt-core>=1.2.0,<2',
     'cryptography',
     # On Linux, the distribution (Ubuntu, Debian, etc) and version are logged in telemetry
