--- transport.h.orig	Thu Sep 22 10:32:26 2005
+++ transport.h	Thu Mar 23 05:00:16 2006
@@ -203,6 +203,7 @@
 #elif defined(__FreeBSD__)
 
 #include <sys/ioctl.h>
+#include <stdio.h>
 #include <camlib.h>
 #include <cam/scsi/scsi_message.h>
 #include <cam/scsi/scsi_pass.h>
