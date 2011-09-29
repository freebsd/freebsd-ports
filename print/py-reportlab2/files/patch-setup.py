--- setup.py.orig	2011-08-05 17:12:44.000000000 +0800
+++ setup.py	2011-08-05 17:13:39.000000000 +0800
@@ -224,7 +224,7 @@
     try:
         infoline("Downloading standard T1 font curves")
 
-        remotehandle = urllib2.urlopen("http://www.reportlab.com/ftp/fonts/pfbfer.zip")
+        remotehandle = open("/usr/ports/distfiles/pfbfer.zip")
         zipdata = StringIO.StringIO(remotehandle.read())
         remotehandle.close()
         archive = zipfile.ZipFile(zipdata)
