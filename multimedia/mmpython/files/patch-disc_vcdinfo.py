
$FreeBSD$

--- disc/vcdinfo.py.orig	Thu Jun 10 20:56:21 2004
+++ disc/vcdinfo.py	Thu Jun 10 20:56:59 2004
@@ -62,9 +62,9 @@
         
         # brute force reading of the device to find out if it is a VCD
         f = open(device,'rb')
-        f.seek(32808, 0)
-        buffer = f.read(50000)
-        f.close()
+	f.seek(32768, 0)
+        buffer = f.read(50040)
+	f.close()
 
         if buffer.find('SVCD') > 0 and buffer.find('TRACKS.SVD') > 0 and \
                buffer.find('ENTRIES.SVD') > 0:
