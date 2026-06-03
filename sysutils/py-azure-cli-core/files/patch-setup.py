--- setup.py.orig	2026-05-01 00:40:32 UTC
+++ setup.py
@@ -43,20 +43,20 @@ DEPENDENCIES = [
 ]
 
 DEPENDENCIES = [
-    'argcomplete~=3.5.2',
-    'azure-cli-telemetry==1.1.0.*',
-    'azure-core~=1.39.0',
+    'argcomplete>=3.5.2',
+    'azure-cli-telemetry>=1.1.0',
+    'azure-core>=1.39.0',
     'azure-mgmt-core>=1.2.0,<2',
     'cryptography',
     # On Linux, the distribution (Ubuntu, Debian, etc) and version are logged in telemetry
     'distro; sys_platform == "linux"',
     'humanfriendly~=10.0',
     'jmespath',
-    'knack~=0.11.0',
+    'knack>=0.11.0',
     'microsoft-security-utilities-secret-masker~=1.0.0b4',
-    'msal-extensions==1.3.1',
+    'msal-extensions>=1.3.1',
     'msal[broker]==1.35.1; sys_platform == "win32"',
-    'msal==1.35.1; sys_platform != "win32"',
+    'msal>=1.35.1; sys_platform != "win32"',
     'packaging>=20.9',
     'pkginfo>=1.5.0.1',
     # psutil can't install on cygwin: https://github.com/Azure/azure-cli/issues/9399
