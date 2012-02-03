--- dvdvideo/media.py.orig	2012-01-20 13:56:29.725075181 +0100
+++ dvdvideo/media.py	2012-01-20 13:57:07.120524761 +0100
@@ -52,7 +52,7 @@
         s = os.stat(filename)
         if stat.S_ISREG(s.st_mode):
             f = self.File(filename)
-        elif stat.S_ISBLK(s.st_mode):
+        elif stat.S_ISBLK(s.st_mode) or stat.S_ISCHR(s.st_mode):
             f = DvdCssFile(filename)
         else:
             raise RuntimeError
