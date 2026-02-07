--- src/ioctl.c.orig	2025-09-23 08:43:53 UTC
+++ src/ioctl.c
@@ -65,6 +65,10 @@
 #   include <scsi/sg.h>
 #   include <stdlib.h>
 #endif
+#ifdef HAVE_CAM_SCSI_SCSI_SG_H
+#   include <cam/scsi/scsi_sg.h>
+#   include <stdlib.h>
+#endif
 #ifdef DVD_STRUCT_IN_DVD_H
 #   include <dvd.h>
 #endif
@@ -1002,7 +1006,7 @@ int ioctl_ReadCPRMMediaId(int i_fd,int *p_agid, uint8_
 {  
     int i_ret;
 
-#if defined( HAVE_LINUX_DVD_STRUCT ) && defined( HAVE_SCSI_SG_H )
+#if (defined( HAVE_LINUX_DVD_STRUCT ) && defined( HAVE_SCSI_SG_H )) || (defined( HAVE_BSD_DVD_STRUCT ) && defined( HAVE_CAM_SCSI_SCSI_SG_H ))
     struct sg_io_hdr io_hdr;
     uint8_t sense[32] = {0};  
     uint8_t cdb[12] = {0};
@@ -1091,7 +1095,7 @@ int ioctl_ReadCPRMMKBPack(int i_fd, int *p_agid, int m
 {
     int i_ret;
 
-#if defined( HAVE_LINUX_DVD_STRUCT ) && defined( HAVE_SCSI_SG_H )
+#if (defined( HAVE_LINUX_DVD_STRUCT ) && defined( HAVE_SCSI_SG_H )) || (defined( HAVE_BSD_DVD_STRUCT ) && defined( HAVE_CAM_SCSI_SCSI_SG_H ))
     uint8_t *sptd_buf = malloc( CPRM_MKB_PACK_SIZE + 4 );
     uint8_t cdb[12] = { 0 };
     uint8_t sense[32] = { 0 };
