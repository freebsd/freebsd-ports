--- setup.py.orig	2022-07-01 22:29:19 UTC
+++ setup.py
@@ -81,7 +81,7 @@ setup(
     packages=find_packages(exclude=['tests']),
     include_package_data=True,
     entry_points={
-        'console_scripts': ['buku=buku:main', 'bukuserver=bukuserver.server:cli']
+        'console_scripts': ['buku=buku:main']
     },
     extras_require={
         "ca-certificates": ["certifi"],
