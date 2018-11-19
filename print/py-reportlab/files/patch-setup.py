--- setup.py.orig	2018-11-06 07:20:18 UTC
+++ setup.py
@@ -288,11 +288,6 @@ reportlab_files= [
 
 def url2data(url,returnRaw=False):
     import io
-    if isPy3:
-        import urllib.request as ureq
-    else:
-        import urllib2 as ureq
-    remotehandle = ureq.urlopen(url)
     try:
         raw = remotehandle.read()
         return raw if returnRaw else io.BytesIO(raw)
@@ -308,9 +303,7 @@ def get_fonts(PACKAGE_DIR, reportlab_files):
         xitmsg = "not downloading T1 font curve files"
     else:
         try:
-            infoline("Downloading standard T1 font curves")
-            zipdata = url2data("http://www.reportlab.com/ftp/pfbfer-20180109.zip")
-            archive = zipfile.ZipFile(zipdata)
+            archive = zipfile.ZipFile("%%DISTDIR%%/%%PFBFER%%")
             dst = pjoin(rl_dir, 'fonts')
 
             for name in archive.namelist():
