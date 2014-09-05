# Unbundle thrift and add it to requirements
# TODO: Upstream
--- ./setup.py.orig	2013-06-13 05:14:17.000000000 +1000
+++ ./setup.py	2014-07-24 20:19:10.032661190 +1000
@@ -18,7 +18,7 @@
     url='http://dev.evernote.com',
     description='Evernote SDK for Python',
     long_description=read('README.md'),
-    packages=find_packages('lib'),
+    packages=find_packages('lib',exclude=["*.thrift", "*,thrift.*", "thrift.*", "thrift"]),
     package_dir={'': 'lib'},
     classifiers=[
         'Development Status :: 5 - Production/Stable',
@@ -29,5 +29,6 @@
     license='BSD',
     install_requires=[
         'oauth2',
+        'thrift',
     ],
 )
