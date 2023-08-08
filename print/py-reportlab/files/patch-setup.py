--- setup.py.orig	2022-06-08 08:27:36 UTC
+++ setup.py
@@ -443,9 +443,7 @@ def get_fonts(PACKAGE_DIR, reportlab_files):
         xitmsg = "not downloading T1 font curve files"
     else:
         try:
-            infoline("Downloading standard T1 font curves")
-            zipdata = url2data("http://www.reportlab.com/ftp/pfbfer-20180109.zip")
-            archive = zipfile.ZipFile(zipdata)
+            archive = zipfile.ZipFile("%%DISTDIR%%/%%PFBFER%%")
             dst = pjoin(rl_dir, 'fonts')
 
             for name in archive.namelist():
