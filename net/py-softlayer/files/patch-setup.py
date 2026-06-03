--- setup.py.orig	2026-03-24 23:23:08 UTC
+++ setup.py
@@ -14,7 +14,7 @@ setup(
     LONG_DESCRIPTION = DESCRIPTION
 
 setup(
-    name='SoftLayer',
+    name='softlayer',
     version='v6.2.9',
     description=DESCRIPTION,
     long_description=LONG_DESCRIPTION,
@@ -37,7 +37,7 @@ setup(
         'prompt_toolkit >= 2',
         'pygments >= 2.0.0',
         'urllib3 >= 1.24',
-        'rich == 14.3.3'
+        'rich >= 14.3.3'
     ],
     keywords=['softlayer', 'cloud', 'slcli', 'ibmcloud'],
     classifiers=[
