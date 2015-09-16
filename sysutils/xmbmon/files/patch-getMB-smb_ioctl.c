--- getMB-smb_ioctl.c.orig	2003-07-05 15:15:24 UTC
+++ getMB-smb_ioctl.c
@@ -5,6 +5,7 @@
 #ifdef HAVE_SMBUS
 /* assume SMBus ioctl support, only for FreeBSD */
 
+#include <sys/param.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <fcntl.h>
@@ -13,7 +14,11 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 
+#if __FreeBSD_version >= 500000
+#include <dev/smbus/smb.h>
+#else
 #include <machine/smb.h>
+#endif
 
 #include "methods.h"
 
@@ -42,10 +47,12 @@ static char buf[128];
 
 static int OpenIO()
 {
-	char byte;
 	struct smbcmd cmd;
 	cmd.slave = smb_slave;
+#if (__FreeBSD_version < 1100071)
+	char byte;
 	cmd.data.byte_ptr = &byte;
+#endif
 
 	if ((iosmb = open(smb_devfile, 000)) < 0) {
 		strcpy(buf, "ioctl(");
@@ -125,7 +132,12 @@ int smbioctl_readB(int slave, int addr)
 	char ret;
 	cmd.slave = slave;
 	cmd.cmd = addr;
+#if (__FreeBSD_version >= 1100071)
+	cmd.rbuf = &ret;
+	cmd.rcount = 1;
+#else
 	cmd.data.byte_ptr = &ret;
+#endif
 	if (ioctl(iosmb, SMB_READB, &cmd) == -1) {
 /*		strcpy(buf, "ioctl(");
 		strcat(buf, smb_devfile + 5);
@@ -142,7 +154,11 @@ void smbioctl_writeB(int slave, int addr
 	struct smbcmd cmd;
 	cmd.slave = slave;
 	cmd.cmd = addr;
+#if (__FreeBSD_version >= 1100071)
+	cmd.wdata.byte = value;
+#else
 	cmd.data.byte = value;
+#endif
 	if (ioctl(iosmb, SMB_WRITEB, &cmd) == -1) {
 		strcpy(buf, "ioctl(");
 		strcat(buf, smb_devfile + 5);
@@ -158,7 +174,12 @@ int smbioctl_readW(int smb_slave, int ad
 	short ret;
 	cmd.slave = smb_slave;
 	cmd.cmd = addr;
+#if (__FreeBSD_version >= 1100071)
+	cmd.rbuf = (char*) &ret;
+	cmd.rcount = 2;
+#else
 	cmd.data.word_ptr = &ret;
+#endif
 	if (ioctl(iosmb, SMB_READW, &cmd) == -1) {
 /*		strcpy(buf, "ioctl(");
 		strcat(buf, smb_devfile + 5);
@@ -175,7 +196,11 @@ void smbioctl_writeW(int slave, int addr
 	struct smbcmd cmd;
 	cmd.slave = slave;
 	cmd.cmd = addr;
+#if (__FreeBSD_version >= 1100071)
+	cmd.wdata.word = value;
+#else
 	cmd.data.word = value;
+#endif
 	if (ioctl(iosmb, SMB_WRITEW, &cmd) == -1) {
 		strcpy(buf, "ioctl(");
 		strcat(buf, smb_devfile + 5);
