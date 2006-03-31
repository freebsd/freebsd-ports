--- disc/lsdvd.py.orig	Sun Feb 26 16:08:37 2006
+++ disc/lsdvd.py	Sun Feb 26 16:32:03 2006
@@ -96,7 +96,7 @@
         self.mime = 'video/mpeg'
 
         l = data[3].split(':')
-        self.length   = (int(l[0])*60+int(l[1]))*60+int(l[2])
+        self.length   = (int(l[0])*60+int(l[1]))*60+float(l[2])
         self.trackno  = int(data[1])
         self.chapters = int(data[5])
         
