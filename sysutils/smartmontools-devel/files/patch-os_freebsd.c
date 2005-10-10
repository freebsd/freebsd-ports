--- os_freebsd.c.orig	Sun Oct  9 13:00:56 2005
+++ os_freebsd.c	Sun Oct  9 13:00:46 2005
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
@@ -120,7 +125,26 @@
   if (parse_ok == CONTROLLER_3WARE_678K_CHAR) {
     char buf[512];
     sprintf(buf,"/dev/twe%d",fdchan->device);
+#ifdef IOCATAREQUEST
+    if ((fdchan->device = open(buf,O_RDWR))<0) {
+#else
     if ((fdchan->atacommand = open(buf,O_RDWR))<0) {
+#endif
+      int myerror = errno; // preserver across free call
+      free(fdchan);
+      errno=myerror;
+      return -1;
+    }
+  }
+
+  if (parse_ok == CONTROLLER_3WARE_9000_CHAR) {
+    char buf[512];
+    sprintf(buf,"/dev/twa%d",fdchan->device);
+#ifdef IOCATAREQUEST
+    if ((fdchan->device = open(buf,O_RDWR))<0) {
+#else
+    if ((fdchan->atacommand = open(buf,O_RDWR))<0) {
+#endif
       int myerror = errno; // preserver across free call
       free(fdchan);
       errno=myerror;
@@ -167,8 +191,13 @@
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
@@ -221,7 +250,7 @@
 }
 
 int ata_command_interface(int fd, smart_command_set command, int select, char *data) {
-#ifndef ATAREQUEST
+#if !defined(ATAREQUEST) && !defined(IOCATAREQUEST)
   // sorry, but without ATAng, we can't do anything here
   printwarning(BAD_KERNEL,NULL);
   errno = ENOSYS;
@@ -229,7 +258,11 @@
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
@@ -238,89 +271,97 @@
 
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
@@ -334,15 +375,19 @@
     unsigned const char failed_lo=0xf4, failed_hi=0x2c;
     unsigned char low,high;
     
-    if ((retval=ioctl(con->atacommand, IOCATA, &iocmd)))
+#ifdef IOCATAREQUEST
+    if ((retval=ioctl(con->device, IOCATAREQUEST, &request)) || request.error)
+#else
+    if ((retval=ioctl(con->atacommand, IOCATA, &iocmd)) || request.error)
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
@@ -355,21 +400,23 @@
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
 
-  if ((retval=ioctl(con->atacommand, IOCATA, &iocmd))) {
-    perror("Failed command: ");
+#ifdef IOCATAREQUEST
+  if ((retval=ioctl(con->device, IOCATAREQUEST, &request)) || request.error)
+#else
+  if ((retval=ioctl(con->atacommand, IOCATA, &iocmd)) || request.error)
+#endif
     return -1;
-  }
   // 
   if (copydata)
     memcpy(data, buff, 512);
@@ -483,16 +530,22 @@
 
 // Interface to ATA devices behind 3ware escalade RAID controller cards.  See os_linux.c
 
+#define BUFFER_LEN_678K_CHAR ( sizeof(struct twe_usercommand) ) // 520
+#define BUFFER_LEN_9000_CHAR ( sizeof(TW_OSLI_IOCTL_NO_DATA_BUF) + sizeof(TWE_Command) ) // 2048
+#define TW_IOCTL_BUFFER_SIZE ( MAX(BUFFER_LEN_678K_CHAR, BUFFER_LEN_9000_CHAR) )
+
 int escalade_command_interface(int fd, int disknum, int escalade_type, smart_command_set command, int select, char *data) {
   // to hold true file descriptor
   struct freebsd_dev_channel* con;
 
   // return value and buffer for ioctl()
   int  ioctlreturn, readdata=0;
-  struct twe_usercommand* cmd = NULL;
+  struct twe_usercommand* cmd_twe = NULL;
+  TW_OSLI_IOCTL_NO_DATA_BUF* cmd_twa = NULL;
+  TWE_Command_ATA* ata = NULL;
 
   // Used by both the SCSI and char interfaces
-  char ioctl_buffer[sizeof(struct twe_usercommand)];
+  char ioctl_buffer[TW_IOCTL_BUFFER_SIZE];
 
   if (disknum < 0) {
     printwarning(NO_DISK_3WARE,NULL);
@@ -503,27 +556,40 @@
   if (isnotopen(&fd,&con))
       return -1;
 
-  memset(ioctl_buffer, 0, sizeof(struct twe_usercommand));
+  memset(ioctl_buffer, 0, TW_IOCTL_BUFFER_SIZE);
 
-  cmd = (struct twe_usercommand*)ioctl_buffer;
-  cmd->tu_command.ata.opcode = TWE_OP_ATA_PASSTHROUGH;
+  if (escalade_type==CONTROLLER_3WARE_9000_CHAR) {
+    cmd_twa = (TW_OSLI_IOCTL_NO_DATA_BUF*)ioctl_buffer;
+    cmd_twa->pdata = ((TW_OSLI_IOCTL_WITH_PAYLOAD*)cmd_twa)->payload.data_buf;
+    cmd_twa->driver_pkt.buffer_length = 512;
+    ata = (TWE_Command_ATA*)&cmd_twa->cmd_pkt.command.cmd_pkt_7k;
+  } else if (escalade_type==CONTROLLER_3WARE_678K_CHAR) {
+    cmd_twe = (struct twe_usercommand*)ioctl_buffer;
+    ata = &cmd_twe->tu_command.ata;
+  } else {
+    pout("Unrecognized escalade_type %d in freebsd_3ware_command_interface(disk %d)\n"
+         "Please contact " PACKAGE_BUGREPORT "\n", escalade_type, disknum);
+    errno=ENOSYS;
+    return -1;
+  }
 
   // Same for (almost) all commands - but some reset below
-  cmd->tu_command.ata.request_id    = 0xFF;
-  cmd->tu_command.ata.unit   = disknum;
-  cmd->tu_command.ata.host_id = 0;
-  cmd->tu_command.ata.status        = 0;           
-  cmd->tu_command.ata.flags         = 0x1;
-  cmd->tu_command.ata.drive_head    = 0x0;
-  cmd->tu_command.ata.sector_num    = 0;
+  ata->opcode        = TWE_OP_ATA_PASSTHROUGH;
+  ata->request_id    = 0xFF;
+  ata->unit          = disknum;
+  ata->host_id       = 0;
+  ata->status        = 0;           
+  ata->flags         = 0x1;
+  ata->drive_head    = 0x0;
+  ata->sector_num    = 0;
 
   // All SMART commands use this CL/CH signature.  These are magic
   // values from the ATA specifications.
-  cmd->tu_command.ata.cylinder_lo   = 0x4F;
-  cmd->tu_command.ata.cylinder_hi   = 0xC2;
+  ata->cylinder_lo   = 0x4F;
+  ata->cylinder_hi   = 0xC2;
   
   // SMART ATA COMMAND REGISTER value
-  cmd->tu_command.ata.command       = ATA_SMART_CMD;
+  ata->command       = ATA_SMART_CMD;
   
   // Is this a command that reads or returns 512 bytes?
   // passthru->param values are:
@@ -538,61 +604,63 @@
       command == IDENTIFY        ||
       command == WRITE_LOG ) {
     readdata=1;
-    cmd->tu_size = 512;
-    cmd->tu_data = data;
-    cmd->tu_command.ata.sgl_offset = 0x5;
-    cmd->tu_command.ata.size         = 0x5;
-    cmd->tu_command.ata.param        = 0xD;
-    cmd->tu_command.ata.sector_count = 0x1;
+    if (escalade_type==CONTROLLER_3WARE_678K_CHAR) {
+      cmd_twe->tu_data = data;
+      cmd_twe->tu_size = 512;
+    }
+    ata->sgl_offset   = 0x5;
+    ata->size         = 0x5;
+    ata->param        = 0xD;
+    ata->sector_count = 0x1;
     // For 64-bit to work correctly, up the size of the command packet
     // in dwords by 1 to account for the 64-bit single sgl 'address'
     // field. Note that this doesn't agree with the typedefs but it's
     // right (agree with kernel driver behavior/typedefs).
-    //if (sizeof(long)==8)
-    //  cmd->tu_command.ata.size++;
+    //if (escalade_type==CONTROLLER_3WARE_9000_CHAR && sizeof(long)==8)
+    //  ata->size++;
   }
   else {
     // Non data command -- but doesn't use large sector 
     // count register values.  
-    cmd->tu_command.ata.sgl_offset = 0x0;
-    cmd->tu_command.ata.size         = 0x5;
-    cmd->tu_command.ata.param        = 0x8;
-    cmd->tu_command.ata.sector_count = 0x0;
+    ata->sgl_offset   = 0x0;
+    ata->size         = 0x5;
+    ata->param        = 0x8;
+    ata->sector_count = 0x0;
   }
   
   // Now set ATA registers depending upon command
   switch (command){
   case CHECK_POWER_MODE:
-    cmd->tu_command.ata.command     = ATA_CHECK_POWER_MODE;
-    cmd->tu_command.ata.features    = 0;
-    cmd->tu_command.ata.cylinder_lo = 0;
-    cmd->tu_command.ata.cylinder_hi = 0;
+    ata->command     = ATA_CHECK_POWER_MODE;
+    ata->features    = 0;
+    ata->cylinder_lo = 0;
+    ata->cylinder_hi = 0;
     break;
   case READ_VALUES:
-    cmd->tu_command.ata.features = ATA_SMART_READ_VALUES;
+    ata->features = ATA_SMART_READ_VALUES;
     break;
   case READ_THRESHOLDS:
-    cmd->tu_command.ata.features = ATA_SMART_READ_THRESHOLDS;
+    ata->features = ATA_SMART_READ_THRESHOLDS;
     break;
   case READ_LOG:
-    cmd->tu_command.ata.features = ATA_SMART_READ_LOG_SECTOR;
+    ata->features = ATA_SMART_READ_LOG_SECTOR;
     // log number to return
-    cmd->tu_command.ata.sector_num  = select;
+    ata->sector_num  = select;
     break;
   case WRITE_LOG:
-    cmd->tu_data = data;
+    if (escalade_type==CONTROLLER_3WARE_9000_CHAR)
+      memcpy(cmd_twa->pdata, data, 512);
     readdata=0;
-    cmd->tu_command.ata.features     = ATA_SMART_WRITE_LOG_SECTOR;
-    cmd->tu_command.ata.sector_count = 1;
-    cmd->tu_command.ata.sector_num   = select;
-    cmd->tu_command.ata.param        = 0xF;  // PIO data write
+    ata->features     = ATA_SMART_WRITE_LOG_SECTOR;
+    ata->sector_num   = select;
+    ata->param        = 0xF;  // PIO data write
     break;
   case IDENTIFY:
     // ATA IDENTIFY DEVICE
-    cmd->tu_command.ata.command     = ATA_IDENTIFY_DEVICE;
-    cmd->tu_command.ata.features    = 0;
-    cmd->tu_command.ata.cylinder_lo = 0;
-    cmd->tu_command.ata.cylinder_hi = 0;
+    ata->command     = ATA_IDENTIFY_DEVICE;
+    ata->features    = 0;
+    ata->cylinder_lo = 0;
+    ata->cylinder_hi = 0;
     break;
   case PIDENTIFY:
     // 3WARE controller can NOT have packet device internally
@@ -600,34 +668,34 @@
     errno=ENODEV;
     return -1;
   case ENABLE:
-    cmd->tu_command.ata.features = ATA_SMART_ENABLE;
+    ata->features = ATA_SMART_ENABLE;
     break;
   case DISABLE:
-    cmd->tu_command.ata.features = ATA_SMART_DISABLE;
+    ata->features = ATA_SMART_DISABLE;
     break;
   case AUTO_OFFLINE:
-    cmd->tu_command.ata.features     = ATA_SMART_AUTO_OFFLINE;
+    ata->features     = ATA_SMART_AUTO_OFFLINE;
     // Enable or disable?
-    cmd->tu_command.ata.sector_count = select;
+    ata->sector_count = select;
     break;
   case AUTOSAVE:
-    cmd->tu_command.ata.features     = ATA_SMART_AUTOSAVE;
+    ata->features     = ATA_SMART_AUTOSAVE;
     // Enable or disable?
-    cmd->tu_command.ata.sector_count = select;
+    ata->sector_count = select;
     break;
   case IMMEDIATE_OFFLINE:
-    cmd->tu_command.ata.features    = ATA_SMART_IMMEDIATE_OFFLINE;
+    ata->features    = ATA_SMART_IMMEDIATE_OFFLINE;
     // What test type to run?
-    cmd->tu_command.ata.sector_num  = select;
+    ata->sector_num  = select;
     break;
   case STATUS_CHECK:
-    cmd->tu_command.ata.features = ATA_SMART_STATUS;
+    ata->features = ATA_SMART_STATUS;
     break;
   case STATUS:
     // This is JUST to see if SMART is enabled, by giving SMART status
     // command. But it doesn't say if status was good, or failing.
     // See below for the difference.
-    cmd->tu_command.ata.features = ATA_SMART_STATUS;
+    ata->features = ATA_SMART_STATUS;
     break;
   default:
     pout("Unrecognized command %d in freebsd_3ware_command_interface(disk %d)\n"
@@ -637,7 +705,19 @@
   }
 
   // Now send the command down through an ioctl()
-  ioctlreturn=ioctl(con->atacommand,TWEIO_COMMAND,cmd);
+  if (escalade_type==CONTROLLER_3WARE_9000_CHAR) {
+#ifdef IOCATAREQUEST
+    ioctlreturn=ioctl(con->device,TW_OSL_IOCTL_FIRMWARE_PASS_THROUGH,cmd_twa);
+#else
+    ioctlreturn=ioctl(con->atacommand,TW_OSL_IOCTL_FIRMWARE_PASS_THROUGH,cmd_twa);
+#endif
+  } else {
+#ifdef IOCATAREQUEST
+    ioctlreturn=ioctl(con->device,TWEIO_COMMAND,cmd_twe);
+#else
+    ioctlreturn=ioctl(con->atacommand,TWEIO_COMMAND,cmd_twe);
+#endif
+  }
   
   // Deal with the different error cases
   if (ioctlreturn) {
@@ -648,9 +728,9 @@
   
   // See if the ATA command failed.  Now that we have returned from
   // the ioctl() call, if passthru is valid, then:
-  // - cmd->tu_command.ata.status contains the 3ware controller STATUS
-  // - cmd->tu_command.ata.command contains the ATA STATUS register
-  // - cmd->tu_command.ata.features contains the ATA ERROR register
+  // - ata->status contains the 3ware controller STATUS
+  // - ata->command contains the ATA STATUS register
+  // - ata->features contains the ATA ERROR register
   //
   // Check bits 0 (error bit) and 5 (device fault) of the ATA STATUS
   // If bit 0 (error bit) is set, then ATA ERROR register is valid.
@@ -658,21 +738,27 @@
   // doesn't make much sense: we don't care in detail why the error
   // happened.
   
-  if (cmd->tu_command.ata.status || (cmd->tu_command.ata.command & 0x21)) {
-    pout("Command failed, ata.status=(0x%2.2x), ata.command=(0x%2.2x), ata.flags=(0x%2.2x)\n",cmd->tu_command.ata.status,cmd->tu_command.ata.command,cmd->tu_command.ata.flags);
+  if (ata->status || (ata->command & 0x21)) {
+    pout("Command failed, ata.status=(0x%2.2x), ata.command=(0x%2.2x), ata.flags=(0x%2.2x)\n",ata->status,ata->command,ata->flags);
     errno=EIO;
     return -1;
   }
   
+  // If this is a read data command, copy data to output buffer
+  if (readdata) {
+    if (escalade_type==CONTROLLER_3WARE_9000_CHAR)
+      memcpy(data, cmd_twa->pdata, 512);
+  }
+
   // For STATUS_CHECK, we need to check register values
   if (command==STATUS_CHECK) {
     
     // To find out if the SMART RETURN STATUS is good or failing, we
     // need to examine the values of the Cylinder Low and Cylinder
     // High Registers.
-    
-    unsigned short cyl_lo=cmd->tu_command.ata.cylinder_lo;
-    unsigned short cyl_hi=cmd->tu_command.ata.cylinder_hi;
+
+    unsigned short cyl_lo=ata->cylinder_lo;
+    unsigned short cyl_hi=ata->cylinder_hi;
     
     // If values in Cyl-LO and Cyl-HI are unchanged, SMART status is good.
     if (cyl_lo==0x4F && cyl_hi==0xC2)
@@ -688,7 +774,7 @@
   
   // copy sector count register (one byte!) to return data
   if (command==CHECK_POWER_MODE)
-    *data=*(char *)&(cmd->tu_command.ata.sector_count);
+    *data=*(char *)&(ata->sector_count);
   
   // look for nonexistent devices/ports
   if (command==IDENTIFY && !nonempty((unsigned char *)data, 512)) {
@@ -709,6 +795,14 @@
   return 0;
 }
 
+static int get_twa_channel_unit (const char* name, int* unit, int* dev) {
+  if (sscanf(name, "twa%d", dev) != 1)
+    return -1;
+  *unit=0; // not really needed for TWA drives, as we handle that seperately
+  return 0;
+}
+
+#ifndef IOCATAREQUEST
 static int get_ata_channel_unit ( const char* name, int* unit, int* dev) {
 #ifndef ATAREQUEST
   *dev=0;
@@ -756,7 +850,7 @@
     return 0;
 #endif
 }
-
+#endif
 
 // Guess device type (ata or scsi) based on device name (FreeBSD
 // specific) SCSI device name in FreeBSD can be sd, sr, scd, st, nst,
@@ -768,6 +862,7 @@
 static const char * fbsd_dev_scsi_tape2 = "nsa";
 static const char * fbsd_dev_scsi_tape3 = "esa";
 static const char * fbsd_dev_twe_disk = "twed";
+static const char * fbsd_dev_twa_disk = "twa";
 
 static int parse_ata_chan_dev(const char * dev_name, struct freebsd_dev_channel *chan) {
   int len;
@@ -788,11 +883,13 @@
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
   
@@ -824,6 +921,16 @@
       }
     }
     return CONTROLLER_3WARE_678K_CHAR;
+  }
+
+  if (!strncmp(fbsd_dev_twa_disk,dev_name,
+	       strlen(fbsd_dev_twa_disk))) {
+    if (chan != NULL) {
+      if (get_twa_channel_unit(dev_name,&(chan->channel),&(chan->device))<0) {
+	return CONTROLLER_UNKNOWN;
+      }
+    }
+    return CONTROLLER_3WARE_9000_CHAR;
   }
 
   // we failed to recognize any of the forms
