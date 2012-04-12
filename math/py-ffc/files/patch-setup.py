--- setup.py.orig	2012-04-06 13:16:19.000000000 -0500
+++ setup.py	2012-04-06 13:16:25.000000000 -0500
@@ -31,5 +31,5 @@
                   "ffc.errorcontrol"],
       package_dir={"ffc": "ffc"},
       scripts = scripts,
-      data_files = [(join("share", "man", "man1"),
+      data_files = [(join("man", "man1"),
                      [join("doc", "man", "man1", "ffc.1.gz")])])
