
$FreeBSD$

--- disc/dvdinfo.py.orig	Thu Jun 10 20:53:51 2004
+++ disc/dvdinfo.py	Thu Jun 10 20:55:02 2004
@@ -115,8 +115,8 @@
 
         # brute force reading of the device to find out if it is a DVD
         f = open(device,'rb')
-        f.seek(32808, 0)
-        buffer = f.read(50000)
+        f.seek(32768, 0) # FreeBSD requires seeking to a 2048 multiple boundary.
+        buffer = f.read(50040) # Read 40 more to compensate for above seek.
 
         if buffer.find('UDF') == -1:
             f.close()
@@ -148,8 +148,8 @@
 
     def isDVDiso(self, f):
         # brute force reading of the device to find out if it is a DVD
-        f.seek(32808, 0)
-        buffer = f.read(50000)
+        f.seek(32768, 0) # FreeBSD requires seeking to a 2048 multiple boundary.
+        buffer = f.read(50040) # Read 40 more to compensate for above seek.
 
         if buffer.find('UDF') == -1:
             return 0
