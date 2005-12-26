--- src/kcddrive.cpp.orig      Thu Dec 15 16:49:47 2005
+++ src/kcddrive.cpp   Thu Dec 15 16:49:47 2005
@@ -27,8 +27,10 @@
 #include <sys/stat.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
+/*
 #include <scsi/scsi.h>
 #include <scsi/sg.h>
+*/
 #include <unistd.h>

 #include <qfile.h>
@@ -177,7 +179,7 @@
         return 0;
     }

-    if (ioctl (fd, SCSI_IOCTL_GET_BUS_NUMBER, &bus) < 0) {
+/*    if (ioctl (fd, SCSI_IOCTL_GET_BUS_NUMBER, &bus) < 0) {
         close (fd);
         return 0;
     }
@@ -185,6 +187,7 @@
         close(fd);
         return 0;
     }
+*/
     id = m_idlun.mux4 & 0xFF;
     lun = (m_idlun.mux4 >> 8)  & 0xFF;

