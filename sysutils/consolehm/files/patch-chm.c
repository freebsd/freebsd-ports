--- chm.c.orig	2000-12-23 07:51:45.000000000 +0100
+++ chm.c	2015-05-01 22:23:03.577465000 +0200
@@ -25,6 +25,7 @@
  *
  */
 
+#include <osreldate.h>
 #include "chm.h"
 
 static int io_file;
@@ -165,6 +165,7 @@
 			printf("Delay: %d microseconds. \n\n",delay);
 			break;
 		default:
+			break;
 	}
 	
 	file_handle = OpenIO();
@@ -279,7 +280,12 @@
 		u_char smb_return;
 		struct smbcmd cmd;
 		cmd.slave=0x5a;
+#if (__FreeBSD_version >= 1100071)
+		cmd.rbuf = &smb_return; 
+		cmd.rcount = 1;
+#else
 		cmd.data.byte_ptr=&smb_return;
+#endif
 		if((open_smb=open("/dev/smb0",000))<0){
 			fprintf(stderr, "Failed to open /dev/smb0.\n");
 			exit (-1);
@@ -315,7 +321,12 @@
 				u_char smb_return;
 				struct smbcmd cmd;
 				cmd.slave=0x5a;
+#if (__FreeBSD_version >= 1100071)
+				cmd.rbuf = &smb_return; 
+				cmd.rcount = 1;
+#else
 				cmd.data.byte_ptr=&smb_return;
+#endif
                                 cmd.cmd=addr;
                                 if(ioctl(open_smb,SMB_READB,&cmd)==-1){
                                         perror("IOCTL");
@@ -342,9 +353,13 @@
 		u_char smb_return;
 		struct smbcmd cmd;
 		cmd.slave=0x5a;
+#if (__FreeBSD_version >= 1100071)
+		cmd.wdata.byte = value;
+#else
 		cmd.data.byte_ptr=&smb_return;
-		cmd.cmd=addr;
 		cmd.data.byte=value;
+#endif
+		cmd.cmd=addr;
 		if(ioctl(open_smb,SMB_WRITEB,&cmd)==-1){
 			perror("IOCTL");
 			return -1;
