--- setup.py.orig	2022-07-01 19:13:56 UTC
+++ setup.py
@@ -35,12 +35,12 @@ setup(
     python_requires='>=3.6',
     install_requires=[
         'prettytable >= 2.5.0',
-        'click >= 8.0.4',
+        'click >= 8.0.3',
         'requests >= 2.20.0',
         'prompt_toolkit >= 2',
         'pygments >= 2.0.0',
         'urllib3 >= 1.24',
-        'rich == 12.3.0'
+        'rich >= 12.3.0'
     ],
     keywords=['softlayer', 'cloud', 'slcli'],
     classifiers=[
