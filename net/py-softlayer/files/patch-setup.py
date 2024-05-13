--- setup.py.orig	2023-12-20 21:04:33 UTC
+++ setup.py
@@ -14,7 +14,7 @@ setup(
     LONG_DESCRIPTION = DESCRIPTION
 
 setup(
-    name='SoftLayer',
+    name='softlayer',
     version='v6.1.11',
     description=DESCRIPTION,
     long_description=LONG_DESCRIPTION,
@@ -39,7 +39,7 @@ setup(
         'prompt_toolkit >= 2',
         'pygments >= 2.0.0',
         'urllib3 >= 1.24',
-        'rich == 13.7.0'
+        'rich >= 13.7.0'
     ],
     keywords=['softlayer', 'cloud', 'slcli'],
     classifiers=[
