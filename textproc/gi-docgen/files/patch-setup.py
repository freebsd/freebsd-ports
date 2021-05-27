--- setup.py.orig	2021-05-26 15:29:06 UTC
+++ setup.py
@@ -55,7 +55,7 @@ package_data = {
 }
 
 data_files = [
-    ('share/pkgconfig', ['gi-docgen.pc']),
+    ('libdata/pkgconfig', ['gi-docgen.pc']),
     ('share/man/man1', ['docs/gi-docgen.1']),
 ]
 
