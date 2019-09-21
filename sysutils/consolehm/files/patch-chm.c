--- chm.c.orig	2000-12-23 06:51:45 UTC
+++ chm.c
@@ -25,6 +25,11 @@
  *
  */
 
+#include <osreldate.h>
+#if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) && defined(__FreeBSD__)
+#include <sys/types.h>
+#include <machine/pio.h>
+#endif
 #include "chm.h"
 
 static int io_file;
@@ -165,6 +170,7 @@ int main (int argc, char **argv)
 			printf("Delay: %d microseconds. \n\n",delay);
 			break;
 		default:
+			break;
 	}
 	
 	file_handle = OpenIO();
@@ -279,7 +285,12 @@ int OpenIO()
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
@@ -315,7 +326,12 @@ int ReadByte(u_char *return_value, int addr)
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
@@ -342,9 +358,13 @@ int WriteByte(int addr, int value)
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
