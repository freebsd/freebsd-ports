--- src/sysdeps/freebsd.c.orig	2010-10-07 14:29:35 UTC
+++ src/sysdeps/freebsd.c
@@ -1441,7 +1441,9 @@ get_data(int iodev, u_char command, int 
 		struct smbcmd cmd;
 
 		bzero(&cmd, sizeof(cmd));
+#if __FreeBSD_version < 1100070
 		cmd.data.byte_ptr = (char *)&byte;
+#endif
 		cmd.slave         = 0x5a;
 		cmd.cmd           = command;
 		if (ioctl(iodev, SMB_READB, (caddr_t)&cmd) == -1)
@@ -1449,6 +1451,9 @@ get_data(int iodev, u_char command, int 
 			close(iodev);
 			return FALSE;
 			}
+#if __FreeBSD_version >= 1100070
+		byte = (u_char)cmd.rdata.byte;
+#endif
 		}
 #endif
 	else
