--- ./setup.py.orig	2012-02-02 15:02:56.000000000 -0800
+++ ./setup.py	2012-02-02 15:04:09.000000000 -0800
@@ -359,12 +359,12 @@
     packages=['virtinst', 'virtconv', 'virtconv.parsers'],
 
     data_files=[
-        ('share/man/man1', [
+        ('man/man1', [
             'man/en/virt-install.1',
             'man/en/virt-clone.1',
             'man/en/virt-image.1',
             'man/en/virt-convert.1']),
-        ('share/man/man5', [
+        ('man/man5', [
             'man/en/virt-image.5']),
     ] + _build_lang_data(),
 
