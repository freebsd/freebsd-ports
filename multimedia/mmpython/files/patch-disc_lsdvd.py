
$FreeBSD$

--- disc/lsdvd.py.orig	Thu Jun 10 20:55:34 2004
+++ disc/lsdvd.py	Thu Jun 10 20:58:14 2004
@@ -173,8 +173,8 @@
 
         # brute force reading of the device to find out if it is a DVD
         f = open(device,'rb')
-        f.seek(32808, 0)
-        buffer = f.read(50000)
+        f.seek(32768, 0)
+        buffer = f.read(50040)
 
         if buffer.find('UDF') == -1:
             f.close()
