--- setup.py.orig	2019-06-13 21:17:46 UTC
+++ setup.py
@@ -31,9 +31,9 @@ DEPENDENCIES = [
 
 DEPENDENCIES = [
     'azure-cli-core',
-    'azure-mgmt-storage==3.3.0',
-    'azure-storage-blob==1.3.1',
-    'azure-mgmt-containerregistry==2.8.0',
+    'azure-mgmt-storage>=3.3.0',
+    'azure-storage-blob>=1.3.1',
+    'azure-mgmt-containerregistry>=2.8.0',
 ]
 
 with open('README.rst', 'r', encoding='utf-8') as f:
