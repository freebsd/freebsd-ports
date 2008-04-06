--- disc/discinfo.py.orig	2004-09-15 05:12:25.000000000 +0900
+++ disc/discinfo.py	2008-04-06 18:36:43.000000000 +0900
@@ -145,14 +145,11 @@
     try:
         fd = os.open(device, os.O_RDONLY | os.O_NONBLOCK)
         if os.uname()[0] == 'FreeBSD':
-            try:
-                cd_toc_entry = array.array('c', '\000'*4096)
-                (address, length) = cd_toc_entry.buffer_info()
-                buf = pack('BBHP', CD_MSF_FORMAT, 0, length, address)
-                s = ioctl(fd, CDIOREADTOCENTRYS, buf)
-                s = CDS_DISC_OK
-            except:
-                s = CDS_NO_DISC
+            cd_toc_entry = array.array('c', '\000'*4096)
+            (address, length) = cd_toc_entry.buffer_info()
+            buf = pack('BBHP', CD_MSF_FORMAT, 0, length, address)
+            s = ioctl(fd, CDIOREADTOCENTRYS, buf)
+            s = CDS_DISC_OK
         else:
             s = ioctl(fd, CDROM_DRIVE_STATUS, CDSL_CURRENT)
     except:
