--- src/device/k3bscsicommand.h.orig	Wed Jan 21 11:20:11 2004
+++ src/device/k3bscsicommand.h	Tue May 11 22:57:03 2004
@@ -17,9 +17,27 @@
 #define _K3B_SCSI_COMMAND_H_
 
 #include <sys/types.h>
+#ifndef __FreeBSD__
 #undef __STRICT_ANSI__
 #include <linux/cdrom.h>
 #define __STRICT_ANSI__
+#else
+#include <sys/types.h>
+#include <stdio.h>
+#include <camlib.h>
+#undef INQUIRY
+#undef READ_10
+#undef READ_12
+#undef READ_BUFFER
+#undef READ_CAPACITY
+#undef REQUEST_SENSE
+#undef START_STOP_UNIT
+#undef SYNCHRONIZE_CACHE
+#undef TEST_UNIT_READY
+#undef WRITE_10
+#undef WRITE_12
+#undef WRITE_BUFFER
+#endif
 
 
 #include <qstring.h>
@@ -96,7 +114,7 @@
   class ScsiCommand
     {
     public:
-      ScsiCommand( int fd );
+//      ScsiCommand( int fd );
       ScsiCommand( const CdDevice* );
       ~ScsiCommand();
 
@@ -109,10 +127,16 @@
 		     size_t len = 0 );
 
     private:
+#ifndef __FreeBSD__
       struct cdrom_generic_command m_cmd;
       struct request_sense m_sense;
-
+#else
+      ScsiCommand( const CdDevice* , struct cam_device *);
+      bool closecam;
+      struct cam_device  *cam;
+      union ccb		ccb;
       int m_fd;
+#endif
       const CdDevice* m_device;
       bool m_needToCloseDevice;
     };
