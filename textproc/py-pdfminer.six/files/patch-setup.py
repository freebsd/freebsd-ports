Provide the console scripts without their ".py" extension.

See also: https://github.com/pdfminer/pdfminer.six/issues/724

--- setup.py.orig	2022-03-19 20:13:07 UTC
+++ setup.py
@@ -33,8 +33,8 @@ setup(
     author_email="pdfminer@goulu.net",
     url="https://github.com/pdfminer/pdfminer.six",
     scripts=[
-        "tools/pdf2txt.py",
-        "tools/dumppdf.py",
+        "tools/pdf2txt",
+        "tools/dumppdf",
     ],
     keywords=[
         "pdf parser",
