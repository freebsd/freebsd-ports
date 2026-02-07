--- src/ioctl.h.orig	2025-09-23 08:43:53 UTC
+++ src/ioctl.h
@@ -106,6 +106,7 @@ typedef union dvd_authinfo dvd_authinfo;
 #define GPCMD_READ_DVD_STRUCTURE 0xad
 #define GPCMD_REPORT_KEY         0xa4
 #define GPCMD_SEND_KEY           0xa3
+#ifndef DVD_STRUCT_IN_SYS_DVDIO_H
  /* DVD struct types */
 #define DVD_STRUCT_PHYSICAL      0x00
 #define DVD_STRUCT_COPYRIGHT     0x01
@@ -122,6 +123,7 @@ typedef union dvd_authinfo dvd_authinfo;
 #define DVD_REPORT_ASF           0x05
 #define DVD_SEND_RPC             0x06
 #define DVD_REPORT_RPC           0x08
+#endif /* ndef DVD_STRUCT_IN_SYS_DVDIO_H */
 #define DVDCSS_INVALIDATE_AGID   0x3f
 
 /*****************************************************************************
