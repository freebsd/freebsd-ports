--- setup.py.orig	2008-11-24 06:35:54.000000000 +0000
+++ setup.py	2008-11-24 06:36:11.000000000 +0000
@@ -28,4 +28,4 @@
     author_email="miguel.filho@gmail.com", packages=["apolicy"],
     package_dir={"apolicy": "src/apolicy"},
     url="http://www.apolicy.org",
-    data_files=[("/etc/apolicy", data_files)])
+    data_files=[("/usr/local/etc/apolicy", data_files)])
