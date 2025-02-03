--- setup.py.orig	2025-01-09 20:04:58 UTC
+++ setup.py
@@ -14,7 +14,7 @@ setup(
     LONG_DESCRIPTION = DESCRIPTION
 
 setup(
-    name='SoftLayer',
+    name='softlayer',
     version='v6.2.6',
     description=DESCRIPTION,
     long_description=LONG_DESCRIPTION,
@@ -38,7 +38,7 @@ setup(
         'prompt_toolkit >= 2',
         'pygments >= 2.0.0',
         'urllib3 >= 1.24',
-        'rich == 13.9.4'
+        'rich >= 13.9.4'
     ],
     keywords=['softlayer', 'cloud', 'slcli', 'ibmcloud'],
     classifiers=[
