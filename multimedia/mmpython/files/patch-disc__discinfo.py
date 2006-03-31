--- disc/discinfo.py.orig	Sun Feb 26 15:51:41 2006
+++ disc/discinfo.py	Sun Feb 26 15:51:44 2006
@@ -139,8 +139,9 @@
     # doesn't work. Suppress that warning for Linux users,
     # until a better solution can be found.
     if os.uname()[0] == 'FreeBSD':
-        CDIOREADTOCENTRYS = 0xc0086305L
+        CDIOREADTOCENTRYS = -1073192187
         CD_MSF_FORMAT = 2
+        CDS_NO_DISC = 1
         
     try:
         fd = os.open(device, os.O_RDONLY | os.O_NONBLOCK)
