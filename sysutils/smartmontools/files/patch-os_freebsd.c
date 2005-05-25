--- os_freebsd.c.orig	Sun Sep  5 09:16:07 2004
+++ os_freebsd.c	Mon May 23 19:29:43 2005
@@ -18,6 +18,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <dirent.h>
+#include <fcntl.h>
 #include <err.h>
 #include <camlib.h>
 #include <cam/scsi/scsi_message.h>
@@ -109,7 +110,11 @@
   }
 
   if (parse_ok == CONTROLLER_ATA) {
+#ifdef IOCATAREQUEST
+    if ((fdchan->device = open(dev,O_RDONLY))<0) {
+#else
     if ((fdchan->atacommand = open("/dev/ata",O_RDWR))<0) {
+#endif
       int myerror = errno;      //preserve across free call
       free (fdchan);
       errno = myerror;
@@ -120,7 +125,11 @@
   if (parse_ok == CONTROLLER_3WARE_678K_CHAR) {
     char buf[512];
     sprintf(buf,"/dev/twe%d",fdchan->device);
+#ifdef IOCATAREQUEST
+    if ((fdchan->device = open(buf,O_RDWR))<0) {
+#else
     if ((fdchan->atacommand = open(buf,O_RDWR))<0) {
+#endif
       int myerror = errno; // preserver across free call
       free(fdchan);
       errno=myerror;
@@ -167,8 +176,13 @@
     free(fdchan->devname);
   
   // close device, if open
+#ifdef IOCATAREQUEST
+  if (fdchan->device)
+    failed=close(fdchan->device);
+#else
   if (fdchan->atacommand)
     failed=close(fdchan->atacommand);
+#endif
 
   if (fdchan->scsicontrol)
     failed=close(fdchan->scsicontrol);
@@ -221,7 +235,7 @@
 }
 
 int ata_command_interface(int fd, smart_command_set command, int select, char *data) {
-#ifndef ATAREQUEST
+#if !defined(ATAREQUEST) && !defined(IOCATAREQUEST)
   // sorry, but without ATAng, we can't do anything here
   printwarning(BAD_KERNEL,NULL);
   errno = ENOSYS;
@@ -229,7 +243,11 @@
 #else
   struct freebsd_dev_channel* con;
   int retval, copydata=0;
+#ifdef IOCATAREQUEST
+  struct ata_ioc_request request;
+#else
   struct ata_cmd iocmd;
+#endif
   unsigned char buff[512];
 
   // check that "file descriptor" is valid
@@ -238,89 +256,97 @@
 
   bzero(buff,512);
 
+#ifdef IOCATAREQUEST
+  bzero(&request,sizeof(struct ata_ioc_request));
+#else
   bzero(&iocmd,sizeof(struct ata_cmd));
+#endif
   bzero(buff,512);
+
+#ifndef IOCATAREQUEST
   iocmd.cmd=ATAREQUEST;
   iocmd.channel=con->channel;
   iocmd.device=con->device;
+#define request iocmd.u.request
+#endif
 
-  iocmd.u.request.u.ata.command=ATA_SMART_CMD;
-  iocmd.u.request.timeout=600;
+  request.u.ata.command=ATA_SMART_CMD;
+  request.timeout=600;
   switch (command){
   case READ_VALUES:
-    iocmd.u.request.u.ata.feature=ATA_SMART_READ_VALUES;
-    iocmd.u.request.u.ata.lba=0xc24f<<8;
-    iocmd.u.request.flags=ATA_CMD_READ;
-    iocmd.u.request.data=buff;
-    iocmd.u.request.count=512;
+    request.u.ata.feature=ATA_SMART_READ_VALUES;
+    request.u.ata.lba=0xc24f<<8;
+    request.flags=ATA_CMD_READ;
+    request.data=buff;
+    request.count=512;
     copydata=1;
     break;
   case READ_THRESHOLDS:
-    iocmd.u.request.u.ata.feature=ATA_SMART_READ_THRESHOLDS;
-    iocmd.u.request.u.ata.count=1;
-    iocmd.u.request.u.ata.lba=1|(0xc24f<<8);
-    iocmd.u.request.flags=ATA_CMD_READ;
-    iocmd.u.request.data=buff;
-    iocmd.u.request.count=512;
+    request.u.ata.feature=ATA_SMART_READ_THRESHOLDS;
+    request.u.ata.count=1;
+    request.u.ata.lba=1|(0xc24f<<8);
+    request.flags=ATA_CMD_READ;
+    request.data=buff;
+    request.count=512;
     copydata=1;
     break;
   case READ_LOG:
-    iocmd.u.request.u.ata.feature=ATA_SMART_READ_LOG_SECTOR;
-    iocmd.u.request.u.ata.lba=select|(0xc24f<<8);
-    iocmd.u.request.u.ata.count=1;
-    iocmd.u.request.flags=ATA_CMD_READ;
-    iocmd.u.request.data=buff;
-    iocmd.u.request.count=512;
+    request.u.ata.feature=ATA_SMART_READ_LOG_SECTOR;
+    request.u.ata.lba=select|(0xc24f<<8);
+    request.u.ata.count=1;
+    request.flags=ATA_CMD_READ;
+    request.data=buff;
+    request.count=512;
     copydata=1;
     break;
   case IDENTIFY:
-    iocmd.u.request.u.ata.command=ATA_IDENTIFY_DEVICE;
-    iocmd.u.request.flags=ATA_CMD_READ;
-    iocmd.u.request.data=buff;
-    iocmd.u.request.count=512;
+    request.u.ata.command=ATA_IDENTIFY_DEVICE;
+    request.flags=ATA_CMD_READ;
+    request.data=buff;
+    request.count=512;
     copydata=1;
     break;
   case PIDENTIFY:
-    iocmd.u.request.u.ata.command=ATA_IDENTIFY_PACKET_DEVICE;
-    iocmd.u.request.flags=ATA_CMD_READ;
-    iocmd.u.request.data=buff;
-    iocmd.u.request.count=512;
+    request.u.ata.command=ATA_IDENTIFY_PACKET_DEVICE;
+    request.flags=ATA_CMD_READ;
+    request.data=buff;
+    request.count=512;
     copydata=1;
     break;
   case ENABLE:
-    iocmd.u.request.u.ata.feature=ATA_SMART_ENABLE;
-    iocmd.u.request.u.ata.lba=0xc24f<<8;
-    iocmd.u.request.flags=ATA_CMD_CONTROL;
+    request.u.ata.feature=ATA_SMART_ENABLE;
+    request.u.ata.lba=0xc24f<<8;
+    request.flags=ATA_CMD_CONTROL;
     break;
   case DISABLE:
-    iocmd.u.request.u.ata.feature=ATA_SMART_DISABLE;
-    iocmd.u.request.u.ata.lba=0xc24f<<8;
-    iocmd.u.request.flags=ATA_CMD_CONTROL;
+    request.u.ata.feature=ATA_SMART_DISABLE;
+    request.u.ata.lba=0xc24f<<8;
+    request.flags=ATA_CMD_CONTROL;
     break;
   case AUTO_OFFLINE:
     // NOTE: According to ATAPI 4 and UP, this command is obsolete
-    iocmd.u.request.u.ata.feature=ATA_SMART_AUTO_OFFLINE;
-    iocmd.u.request.u.ata.lba=select|(0xc24f<<8);
-    iocmd.u.request.flags=ATA_CMD_CONTROL;
+    request.u.ata.feature=ATA_SMART_AUTO_OFFLINE;
+    request.u.ata.lba=select|(0xc24f<<8);
+    request.flags=ATA_CMD_CONTROL;
     break;
   case AUTOSAVE:
-    iocmd.u.request.u.ata.feature=ATA_SMART_AUTOSAVE;
-    iocmd.u.request.u.ata.count=0xf1;  // to enable autosave
-    iocmd.u.request.u.ata.lba=0xc24f<<8;
-    iocmd.u.request.flags=ATA_CMD_CONTROL;
+    request.u.ata.feature=ATA_SMART_AUTOSAVE;
+    request.u.ata.count=0xf1;  // to enable autosave
+    request.u.ata.lba=0xc24f<<8;
+    request.flags=ATA_CMD_CONTROL;
     break;
   case IMMEDIATE_OFFLINE:
-    iocmd.u.request.u.ata.feature=ATA_SMART_IMMEDIATE_OFFLINE;
-    iocmd.u.request.u.ata.lba = select|(0xc24f<<8); // put test in sector
-    iocmd.u.request.flags=ATA_CMD_CONTROL;
+    request.u.ata.feature=ATA_SMART_IMMEDIATE_OFFLINE;
+    request.u.ata.lba = select|(0xc24f<<8); // put test in sector
+    request.flags=ATA_CMD_CONTROL;
     break;
   case STATUS_CHECK: // same command, no HDIO in FreeBSD
   case STATUS:
     // this command only says if SMART is working.  It could be
     // replaced with STATUS_CHECK below.
-    iocmd.u.request.u.ata.feature=ATA_SMART_STATUS;
-    iocmd.u.request.u.ata.lba=0xc24f<<8;
-    iocmd.u.request.flags=ATA_CMD_CONTROL;
+    request.u.ata.feature=ATA_SMART_STATUS;
+    request.u.ata.lba=0xc24f<<8;
+    request.flags=ATA_CMD_CONTROL;
     break;
   default:
     pout("Unrecognized command %d in ata_command_interface()\n"
@@ -334,15 +360,19 @@
     unsigned const char failed_lo=0xf4, failed_hi=0x2c;
     unsigned char low,high;
     
+#ifdef IOCATAREQUEST
+    if ((retval=ioctl(con->device, IOCATAREQUEST, &request)))
+#else
     if ((retval=ioctl(con->atacommand, IOCATA, &iocmd)))
+#endif
       return -1;
 
 #if __FreeBSD_version < 502000
     printwarning(NO_RETURN,NULL);
 #endif
 
-    high = (iocmd.u.request.u.ata.lba >> 16) & 0xff;
-    low = (iocmd.u.request.u.ata.lba >> 8) & 0xff;
+    high = (request.u.ata.lba >> 16) & 0xff;
+    low = (request.u.ata.lba >> 8) & 0xff;
     
     // Cyl low and Cyl high unchanged means "Good SMART status"
     if (low==normal_lo && high==normal_hi)
@@ -355,18 +385,22 @@
     // We haven't gotten output that makes sense; print out some debugging info
     char buf[512];
     sprintf(buf,"CMD=0x%02x\nFR =0x%02x\nNS =0x%02x\nSC =0x%02x\nCL =0x%02x\nCH =0x%02x\nRETURN =0x%04x\n",
-            (int)iocmd.u.request.u.ata.command,
-            (int)iocmd.u.request.u.ata.feature,
-            (int)iocmd.u.request.u.ata.count,
-            (int)((iocmd.u.request.u.ata.lba) & 0xff),
-            (int)((iocmd.u.request.u.ata.lba>>8) & 0xff),
-            (int)((iocmd.u.request.u.ata.lba>>16) & 0xff),
-            (int)iocmd.u.request.error);
+            (int)request.u.ata.command,
+            (int)request.u.ata.feature,
+            (int)request.u.ata.count,
+            (int)((request.u.ata.lba) & 0xff),
+            (int)((request.u.ata.lba>>8) & 0xff),
+            (int)((request.u.ata.lba>>16) & 0xff),
+            (int)request.error);
     printwarning(BAD_SMART,buf);
     return 0;   
   }
 
+#ifdef IOCATAREQUEST
+  if ((retval=ioctl(con->device, IOCATAREQUEST, &request))) {
+#else
   if ((retval=ioctl(con->atacommand, IOCATA, &iocmd))) {
+#endif
     perror("Failed command: ");
     return -1;
   }
@@ -637,7 +671,11 @@
   }
 
   // Now send the command down through an ioctl()
+#ifdef IOCATAREQUEST
+  ioctlreturn=ioctl(con->device,TWEIO_COMMAND,cmd);
+#else
   ioctlreturn=ioctl(con->atacommand,TWEIO_COMMAND,cmd);
+#endif
   
   // Deal with the different error cases
   if (ioctlreturn) {
@@ -709,6 +747,7 @@
   return 0;
 }
 
+#ifndef IOCATAREQUEST
 static int get_ata_channel_unit ( const char* name, int* unit, int* dev) {
 #ifndef ATAREQUEST
   *dev=0;
@@ -756,7 +795,7 @@
     return 0;
 #endif
 }
-
+#endif
 
 // Guess device type (ata or scsi) based on device name (FreeBSD
 // specific) SCSI device name in FreeBSD can be sd, sr, scd, st, nst,
@@ -788,11 +827,13 @@
   // form /dev/ad* or ad*
   if (!strncmp(fbsd_dev_ata_disk_prefix, dev_name,
                strlen(fbsd_dev_ata_disk_prefix))) {
+#ifndef IOCATAREQUEST
     if (chan != NULL) {
       if (get_ata_channel_unit(dev_name,&(chan->channel),&(chan->device))<0) {
         return CONTROLLER_UNKNOWN;
       }
     }
+#endif
     return CONTROLLER_ATA;
   }
   
