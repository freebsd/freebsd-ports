--- Lib/Uuid.py.orig	Fri Aug 10 07:28:49 2001
+++ Lib/Uuid.py	Mon Jan  7 14:49:45 2002
@@ -64,7 +64,7 @@
     newUuid = ''
     curUuid = uuid
     for ctr in range(16):
-        num = int(curUuid & 0xF)
+        num = int(curUuid & 0xFF)
         newChar = chr(num)
         curUuid = curUuid >> 8
         newUuid = newChar + newUuid
