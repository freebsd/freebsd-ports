
$FreeBSD$

--- video/vcdinfo.py.orig	Thu Jun 10 20:58:51 2004
+++ video/vcdinfo.py	Thu Jun 10 20:59:19 2004
@@ -85,9 +85,9 @@
         
         # brute force reading of the bin to find out if it is a VCD
         f = open(bin,'rb')
-        f.seek(32808, 0)
-        buffer = f.read(50000)
-        f.close()
+        f.seek(32768, 0) # FreeBSD requires seeking to 2048 multiple boundary.
+        buffer = f.read(50040) # Read 40 more to compensate for above seek.
+        f.close()
 
         if buffer.find('SVCD') > 0 and buffer.find('TRACKS.SVD') > 0 and \
                buffer.find('ENTRIES.SVD') > 0:
