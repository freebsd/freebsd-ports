--- src/plugins/rom_drives.py.orig	Sun Oct 16 18:18:49 2005
+++ src/plugins/rom_drives.py	Sun Feb 26 17:59:30 2006
@@ -70,7 +70,7 @@
         # FreeBSD ioctls - there is no CDROM.py...
         CDIOCEJECT = 0x20006318
         CDIOCCLOSE = 0x2000631c
-        CDIOREADTOCENTRYS = 0xc0086305
+        CDIOREADTOCENTRYS = -1073192187
         CD_LBA_FORMAT = 1
         CD_MSF_FORMAT = 2
         CDS_NO_DISC = 1
