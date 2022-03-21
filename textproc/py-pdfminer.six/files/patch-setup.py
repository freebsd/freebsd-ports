Provide the console scripts without their ".py" extension.

See also: https://github.com/pdfminer/pdfminer.six/issues/724

--- setup.py.orig	2022-02-21 17:52:51 UTC
+++ setup.py
@@ -28,8 +28,8 @@ setup(
     author_email='pdfminer@goulu.net',
     url='https://github.com/pdfminer/pdfminer.six',
     scripts=[
-        'tools/pdf2txt.py',
-        'tools/dumppdf.py',
+        'tools/pdf2txt',
+        'tools/dumppdf',
     ],
     keywords=[
         'pdf parser',
