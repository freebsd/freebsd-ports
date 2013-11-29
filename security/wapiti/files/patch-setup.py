--- ./setup.py.orig	2013-10-20 12:04:17.000000000 +0000
+++ ./setup.py	2013-11-28 19:47:25.000000000 +0000
@@ -14,7 +14,7 @@
                             "README",
                             "TODO",
                             "VERSION"]))
-doc_and_conf_files.append(("share/man/man1", ["doc/wapiti.1.gz"]))
+doc_and_conf_files.append(("man/man1", ["doc/wapiti.1.gz"]))
 
 # Main
 setup(
