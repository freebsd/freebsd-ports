# fixing max urllib3, updating authors
# https://github.com/elastic/elasticsearch-py/commit/4352e56174b77560d2f86801cb1ad32440bb2d32

--- setup.py.orig	2019-01-21 08:52:05 UTC
+++ setup.py
@@ -12,7 +12,7 @@ long_description = f.read().strip()
 f.close()
 
 install_requires = [
-    'urllib3<1.23,>=1.21.1',
+    'urllib3>=1.21.1',
 ]
 tests_require = [
     'requests>=2.0.0, <3.0.0',
