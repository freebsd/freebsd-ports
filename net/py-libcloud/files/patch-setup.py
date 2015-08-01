--- setup.py.orig	2014-11-19 16:00:24 UTC
+++ setup.py
@@ -47,7 +47,6 @@ DOC_TEST_MODULES = ['libcloud.compute.dr
 SUPPORTED_VERSIONS = ['2.5', '2.6', '2.7', 'PyPy', '3.x']
 
 TEST_REQUIREMENTS = [
-    'backports.ssl_match_hostname',
     'mock'
 ]
 
@@ -222,10 +221,6 @@ class CoverageCommand(Command):
 
 forbid_publish()
 
-install_requires = ['backports.ssl_match_hostname']
-if pre_python26:
-    install_requires.extend(['ssl', 'simplejson'])
-
 setup(
     name='apache-libcloud',
     version=read_version_string(),
@@ -234,7 +229,6 @@ setup(
                 ' and documentation, please see http://libcloud.apache.org',
     author='Apache Software Foundation',
     author_email='dev@libcloud.apache.org',
-    install_requires=install_requires,
     packages=get_packages('libcloud'),
     package_dir={
         'libcloud': 'libcloud',
