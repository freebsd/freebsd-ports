--- setup.py.orig	2025-06-27 19:33:14 UTC
+++ setup.py
@@ -14,7 +14,7 @@ setup(
     LONG_DESCRIPTION = DESCRIPTION
 
 setup(
-    name='SoftLayer',
+    name='softlayer',
     version='v6.2.7',
     description=DESCRIPTION,
     long_description=LONG_DESCRIPTION,
@@ -38,7 +38,7 @@ setup(
         'prompt_toolkit >= 2',
         'pygments >= 2.0.0',
         'urllib3 >= 1.24',
-        'rich == 14.0.0'
+        'rich >= 14.0.0'
     ],
     keywords=['softlayer', 'cloud', 'slcli', 'ibmcloud'],
     classifiers=[
