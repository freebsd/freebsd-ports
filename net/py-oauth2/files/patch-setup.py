--- ./setup.py.orig	2014-03-15 23:48:44.604925965 +1100
+++ ./setup.py	2014-03-15 23:49:01.462781884 +1100
@@ -31,7 +31,7 @@
       author="Joe Stump",
       author_email="joe@simplegeo.com",
       url="http://github.com/simplegeo/python-oauth2",
-      packages = find_packages(),
+      packages = find_packages(exclude=['tests']),
       install_requires = ['httplib2'],
       license = "MIT License",
       keywords="oauth",
