--- setup.py.orig	2016-01-13 08:43:51 UTC
+++ setup.py
@@ -42,6 +42,9 @@ setup(name='rsa',
       install_requires=[
           'pyasn1 >= 0.1.3',
       ],
+      tests_require=[
+          'unittest2',
+      ],
       entry_points={'console_scripts': [
           'pyrsa-priv2pub = rsa.util:private_to_public',
           'pyrsa-keygen = rsa.cli:keygen',
