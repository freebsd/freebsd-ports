--- setup.py.orig	Sun Mar 18 23:42:50 2007
+++ setup.py	Sun Jun 24 18:34:05 2007
@@ -24,9 +24,6 @@
     packages=find_packages(exclude=['ez_setup']),
     zip_safe=False,
     include_package_data=True,
-    install_requires=[
-        "Routes>=1.1", "simplejson>=1.4",
-        ],
     classifiers=["Development Status :: 4 - Beta",
                  "Intended Audience :: Developers",
                  "License :: OSI Approved :: BSD License",
