--- setup.py.orig	2023-04-17 17:36:38 UTC
+++ setup.py
@@ -69,7 +69,6 @@ setup(
     license='Apache 2.0',
     packages=find_packages(exclude=['examples', 'tests']),
     package_data={
-        "": ["LICENSE", "CONTRIBUTING.md"],
         "planet": ["data/*"],
     },
     include_package_data=True,
