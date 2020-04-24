--- setup.py.orig	2017-12-01 09:46:38 UTC
+++ setup.py
@@ -70,8 +70,7 @@ setup(
         'Programming Language :: Python :: 3',
         'Programming Language :: Python :: 3.6'
     ],
-    setup_requires=["nose", "coverage", "mock"],
-    install_requires=["py-radix==0.10.0"] + (
+    install_requires=["py-radix>=0.10.0"] + (
         ["future", "ipaddress"] if sys.version_info.major == 2 else []
     ),
     packages=find_packages(exclude=['tests', 'tests.*']),
