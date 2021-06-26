# Remove experimental HTTP/2 support, issues with Twisted and h2
--- setup.py.orig	2021-04-06 14:48:02 UTC
+++ setup.py
@@ -19,7 +19,6 @@ def has_environment_marker_platform_impl_support():
 
 
 install_requires = [
-    'Twisted[http2]>=17.9.0',
     'cryptography>=2.0',
     'cssselect>=0.9.1',
     'itemloaders>=1.0.1',
@@ -31,7 +30,6 @@ install_requires = [
     'zope.interface>=4.1.3',
     'protego>=0.1.15',
     'itemadapter>=0.1.0',
-    'h2>=3.0,<4.0',
 ]
 extras_require = {}
 cpython_dependencies = [
