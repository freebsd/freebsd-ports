# Fix UnicodeDecodeError: 'ascii' codec can't decode error

--- setup.py.orig	2021-06-18 10:28:47 UTC
+++ setup.py
@@ -3,12 +3,8 @@ with open("README") as f:
 with open("README") as f:
     long_description = f.read()
 
+version = '1.19.3'
 
-def local_scheme(version):
-    """Skip the local version (eg. +xyz of 0.6.1.dev4+gdf99fe2)
-    to be able to upload to Test PyPI"""
-    return ""
-
 setup(name='twitter',
       description="An API and command-line toolset for Twitter (twitter.com)",
       long_description=long_description,
@@ -43,8 +39,6 @@ setup(name='twitter',
       packages=find_packages(exclude=['ez_setup', 'examples', 'tests']),
       include_package_data=True,
       zip_safe=True,
-      use_scm_version={"local_scheme": local_scheme},
-      setup_requires=["setuptools_scm"],
       entry_points="""
       # -*- Entry points: -*-
       [console_scripts]
