--- PyPlucker/helper/gettext.py.orig	Wed May 19 18:18:19 2004
+++ PyPlucker/helper/gettext.py	Fri Oct 29 16:04:44 2004
@@ -128,7 +128,7 @@
                 else:
                         return # assume C locale
 
-                if _lsbStrToInt(buffer[:4]) != 0x950412de:
+                if _lsbStrToInt(buffer[:4]) != 0x950412deL:
                         # magic number doesn't match
                         raise error, 'Bad magic number in %s' % (catalog,)
 
@@ -173,7 +173,7 @@
                         f = open(file, "wb")
                 except IOError:
                         raise error, "can't open " + file + " for writing"
-                f.write(_intToLsbStr(0x950412de))    # magic number
+                f.write(_intToLsbStr(0x950412deL))   # magic number
                 f.write(_intToLsbStr(0))             # revision
                 f.write(_intToLsbStr(len(self.cat))) # nstrings
 
