--- src/plugins/rom_drives.py	Tue Aug 17 21:51:52 2004
+++ src/plugins/rom_drives.py	Tue Aug 17 21:50:55 2004
@@ -409,9 +409,19 @@
                     data = array.array('c', '\000'*4096)
                     (address, length) = data.buffer_info()
                     buf = pack('BBHP', CD_MSF_FORMAT, 0, length, address)
-                    s = ioctl(fd, CDIOREADTOCENTRYS, buf)
+                    #s = ioctl(fd, CDIOREADTOCENTRYS, buf)
+
+                    # Above s = ioctl(... doesn't seem to work.
+                    # Instead let's try and read from the disc, if it
+                    # succeeds then there must be a disc in the drive.
+                    # Nasty but it seems to work...
+                    fd2 = open(media.devicename, 'rb')
+                    fd2.seek(32768)
+                    fd2.read(1)
+                    fd2.close()
                     s = CDS_DISC_OK
                 except:
+                    fd2.close()
                     s = CDS_NO_DISC
             else:
                 s = ioctl(fd, CDROM_DRIVE_STATUS, CDSL_CURRENT)
