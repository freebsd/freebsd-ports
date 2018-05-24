--- setup.py.orig	2017-12-05 23:36:26 UTC
+++ setup.py
@@ -56,11 +56,11 @@ setup(
     package_dir={"pyaff4": "pyaff4"},
     install_requires=[
         "future",
-        "aff4-snappy == 0.5.1",
-        "rdflib[sparql] == 4.2.2",
-        "intervaltree == 2.1.0",
-        "pyblake2 == 0.9.3",
-        "expiringdict == 1.1.4",
+        "python-snappy >= 0.5.1",
+        "rdflib[sparql] >= 4.2.2",
+        "intervaltree >= 2.1.0",
+        "pyblake2 >= 0.9.3",
+        "expiringdict >= 1.1.4",
         "html5lib",
     ],
     extras_require=dict(
