--- setup.py.orig	2018-05-21 01:06:59 UTC
+++ setup.py
@@ -25,7 +25,6 @@ setuptools.setup(
     author='Florian Ruechel',
     tests_require=['pytest >= 2.5.2', 'mock', 'sphinx', 'pytest-mock'],
     install_requires=install_requires,
-    setup_requires=['pytest-runner'],
     author_email='fruechel@atlassian.com',
     description='Flask SAML integration',
     long_description=long_description,
