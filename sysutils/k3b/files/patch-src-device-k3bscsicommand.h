--- src/device/k3bscsicommand.h.orig	Wed Jan 21 11:20:11 2004
+++ src/device/k3bscsicommand.h	Fri Feb 13 21:03:38 2004
@@ -1,10 +1,10 @@
 /* 
  *
- * $Id: k3bscsicommand.h,v 1.3 2004/01/21 10:20:11 trueg Exp $
+ * $Id: k3bscsicommand.h,v 1.2 2003/12/19 19:40:40 trueg Exp $
  * Copyright (C) 2003 Sebastian Trueg <trueg@k3b.org>
  *
  * This file is part of the K3b project.
- * Copyright (C) 1998-2004 Sebastian Trueg <trueg@k3b.org>
+ * Copyright (C) 1998-2003 Sebastian Trueg <trueg@k3b.org>
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
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
@@ -87,16 +105,24 @@
   }
 
 
+#ifndef __FreeBSD__
   enum TransportDirection {
     TR_DIR_NONE,
     TR_DIR_READ,
     TR_DIR_WRITE
   };
+#else
+  enum TransportDirection {
+    TR_DIR_NONE = 0,
+    TR_DIR_READ = CAM_DIR_IN,
+    TR_DIR_WRITE = CAM_DIR_OUT
+  };
+#endif
 
   class ScsiCommand
     {
     public:
-      ScsiCommand( int fd );
+//      ScsiCommand( int fd );
       ScsiCommand( const CdDevice* );
       ~ScsiCommand();
 
@@ -109,9 +135,13 @@
 		     size_t len = 0 );
 
     private:
+#ifndef __FreeBSD__
       struct cdrom_generic_command m_cmd;
       struct request_sense m_sense;
-
+#else
+      struct cam_device  *cam;
+      union ccb		ccb;
+#endif
       int m_fd;
       const CdDevice* m_device;
       bool m_needToCloseDevice;
