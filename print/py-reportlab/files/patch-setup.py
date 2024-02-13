--- setup.py.orig	2024-02-13 07:54:28 UTC
+++ setup.py
@@ -202,9 +202,7 @@ def get_fonts(PACKAGE_DIR, reportlab_files):
         xitmsg = "not downloading T1 font curve files"
     else:
         try:
-            infoline("Downloading standard T1 font curves")
-            zipdata = url2data("https://www.reportlab.com/ftp/pfbfer-20180109.zip")
-            archive = zipfile.ZipFile(zipdata)
+            archive = zipfile.ZipFile("%%DISTDIR%%/%%PFBFER%%")
             dst = pjoin(rl_dir, 'fonts')
 
             for name in archive.namelist():
