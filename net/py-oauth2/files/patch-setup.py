# This package installs its 'test' module in site-packages/. Patch it out
# so tests/ is excluded from installation

--- setup.py.orig	2015-09-12 12:43:42 UTC
+++ setup.py
@@ -45,7 +45,7 @@ setup(name=PKG,
         "Natural Language :: English",
         "License :: OSI Approved :: MIT License"
       ],
-      packages = find_packages(),
+      packages = find_packages(exclude=['tests']),
       install_requires = ['httplib2'],
       license = "MIT License",
       keywords="oauth",
