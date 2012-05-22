--- setup.py.orig	2012-05-08 06:56:28.000000000 +0200
+++ setup.py	2012-05-19 13:42:13.000000000 +0200
@@ -11,7 +11,7 @@
 from requests.compat import is_py3
 
 try:
-    from setuptools import setup
+    from setuptools import setup, find_packages
     # hush pyflakes
     setup
 except ImportError:
@@ -21,31 +21,8 @@
     os.system('python setup.py sdist upload')
     sys.exit()
 
-packages = [
-    'requests',
-    'requests.packages',
-    'requests.packages.urllib3',
-    'requests.packages.urllib3.packages',
-    'requests.packages.urllib3.packages.ssl_match_hostname',
-    'requests.packages.urllib3.packages.mimetools_choose_boundary',
-]
-
-# certifi is a Python package containing a CA certificate bundle for SSL verification.
-# On certain supported platforms (e.g., Red Hat / Debian / FreeBSD), Requests can
-# use the system CA bundle instead; see `requests.utils` for details.
-# If your platform is supported, set `requires` to [] instead:
-requires = ['certifi>=0.0.7']
-
-# chardet is used to optimally guess the encodings of pages that don't declare one.
-# At this time, chardet is not a required dependency. However, it's sufficiently
-# important that pip/setuptools should install it when it's unavailable.
-if is_py3:
-    chardet_package = 'chardet2'
-else:
-    chardet_package = 'chardet>=1.0.0'
-    requires.append('oauthlib>=0.1.0,<0.2.0')
-
-requires.append(chardet_package)
+# FreeBSD ports tree, provides only chardet2
+requires = ['certifi>=0.0.7', 'chardet>=2.0.0']
 
 # The async API in requests.async requires the gevent package.
 # This is also not a required dependency.
@@ -62,7 +39,7 @@
     author='Kenneth Reitz',
     author_email='me@kennethreitz.com',
     url='http://python-requests.org',
-    packages=packages,
+    packages=find_packages(exclude=['requests.packages.url*']),
     package_data={'': ['LICENSE', 'NOTICE']},
     include_package_data=True,
     install_requires=requires,
