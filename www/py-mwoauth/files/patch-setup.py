Relax version requirements for www/py-pyjwt

Obtained from:

https://github.com/mediawiki-utilities/python-mwoauth/commit/4cff1c2165d74010b538c8f061e7488d34417bcb

--- setup.py.orig	2022-01-09 13:39:26 UTC
+++ setup.py
@@ -22,7 +22,7 @@ setup(
     packages=find_packages(),
     long_description=read('README.rst'),
     install_requires=[
-        'PyJWT>=1.0.1,<2.0.0',
+        'PyJWT>=1.0.1',
         'oauthlib',
         'requests',
         'requests-oauthlib',
