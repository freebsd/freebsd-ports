--- kover/cdrom.cc.orig	Fri Feb  7 17:05:06 2003
+++ kover/cdrom.cc	Mon Dec 29 04:51:51 2003
@@ -64,7 +64,14 @@
 				return -1;
 	 }
 	 if (cdrom_fd > 0)
+#ifdef __FreeBSD__
+         {
+                  ioctl(cdrom_fd,CDIOCALLOW);
+                  ioctl(cdrom_fd,CDIOCEJECT);
+         }
+#else
 		  ioctl(cdrom_fd,CDROMEJECT);
+#endif
 	 else
 		  return -1;
 	 close();
