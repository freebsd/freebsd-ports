--- src/core/device/k3bscsicommand.h.orig	Mon Oct 20 22:29:12 2003
+++ src/core/device/k3bscsicommand.h	Fri Nov  7 12:35:44 2003
@@ -17,9 +17,9 @@
 #define _K3B_SCSI_COMMAND_H_
 
 #include <sys/types.h>
-#undef __STRICT_ANSI__
-#include <linux/cdrom.h>
-#define __STRICT_ANSI__
+#include <stdio.h>
+#include <camlib.h>
+#include <qstring.h>
 
 
 namespace K3bCdDevice
@@ -29,15 +29,17 @@
   // see transport.hxx for a BSD version
 
   enum TransportDirection {
-    TR_DIR_NONE,
-    TR_DIR_READ,
-    TR_DIR_WRITE
+    TR_DIR_NONE = 0,
+    TR_DIR_READ = CAM_DIR_IN,
+    TR_DIR_WRITE = CAM_DIR_OUT
   };
 
   class ScsiCommand
     {
     public:
-      ScsiCommand( int fd );
+      ScsiCommand( const QString & passDevice );
+
+      ~ScsiCommand();
 
       void clear();
 
@@ -48,10 +50,9 @@
 		     size_t len = 0 );
 
     private:
-      struct cdrom_generic_command m_cmd;
-      struct request_sense m_sense;
-
-      int m_fd;
+            struct cam_device  *cam;
+            union ccb		ccb;
+      QString m_passDevice;
     };
 }
 
