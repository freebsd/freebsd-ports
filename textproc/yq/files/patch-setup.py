--- setup.py.orig	2024-04-27 04:49:23 UTC
+++ setup.py
@@ -15,7 +15,7 @@ setup(
     use_scm_version={
         "write_to": "yq/version.py",
     },
-    setup_requires=["setuptools_scm >= 7, <8"],
+    setup_requires=["setuptools_scm >= 7"],
     install_requires=[
         "PyYAML >= 5.3.1",
         "xmltodict >= 0.11.0",
