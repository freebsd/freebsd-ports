--- setup.py.orig	2021-09-02 20:03:31 UTC
+++ setup.py
@@ -24,7 +24,7 @@ with open(os.path.join(PACKAGE_ROOT, 'README.rst')) as
 
 
 REQUIREMENTS = [
-    'google-crc32c >= 1.0, <= 1.1.2',
+    'google-crc32c >= 1.0, < 2.0dev',
 ]
 EXTRAS_REQUIRE = {
     'requests': [
