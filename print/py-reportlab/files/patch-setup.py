--- setup.py.orig	2014-02-14 14:22:37 UTC
+++ setup.py
@@ -241,11 +241,7 @@ reportlab_files= [
         ]
 
 def get_fonts(PACKAGE_DIR, reportlab_files):
-    import sys, os, os.path, zipfile, io
-    if isPy3:
-        import urllib.request as ureq
-    else:
-        import urllib2 as ureq
+    import sys, os, os.path, zipfile
     rl_dir = PACKAGE_DIR['reportlab']
     if not [x for x in reportlab_files if not os.path.isfile(pjoin(rl_dir,x))]:
         infoline("Standard T1 font curves already downloaded")
@@ -254,12 +250,7 @@ def get_fonts(PACKAGE_DIR, reportlab_fil
         infoline('not downloading T1 font curve files')
         return
     try:
-        infoline("Downloading standard T1 font curves")
-
-        remotehandle = ureq.urlopen("http://www.reportlab.com/ftp/pfbfer-20070710.zip")
-        zipdata = io.BytesIO(remotehandle.read())
-        remotehandle.close()
-        archive = zipfile.ZipFile(zipdata)
+        archive = zipfile.ZipFile("%%DISTDIR%%/%%PFBFER%%")
         dst = pjoin(rl_dir, 'fonts')
 
         for name in archive.namelist():
