--- src/totem-disc.c.orig	Sun Mar 13 08:37:57 2005
+++ src/totem-disc.c	Wed Mar 23 03:29:26 2005
@@ -34,18 +34,40 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
-#include <mntent.h>
 #include <string.h>
 
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 
+#ifdef __FreeBSD__
+#include <sys/cdio.h>
+#include <sys/disklabel.h>
+
+#define CDROM_DRIVE_STATUS      0x5326
+#define CDROM_DISC_STATUS       0x5327
+#define CDS_AUDIO               100
+#define CDS_MIXED               105
+#define CDS_DATA_1              101
+#define CDS_DATA_2              102
+#define CDS_NO_INFO             0       /* if not implemented */
+#define CDS_NO_DISC             1
+#define CDS_TRAY_OPEN           2
+#define CDS_DRIVE_NOT_READY     3
+#define CDS_DISC_OK             4
+#define CDS_XA_2_1              103
+#define CDS_XA_2_2              104
+#define CDC_DVD                 0x8000
+#define ENOMEDIUM ENODEV
+#define CDROM_GET_CAPABILITY CDIOCCLRDEBUG
+#else
+#include <mntent.h>
+#include <linux/cdrom.h>
+#endif
+
 #include <glib.h>
 #include <glib/gi18n.h>
 #include <libgnomevfs/gnome-vfs.h>
 
-#include <linux/cdrom.h>
-
 #include "totem-disc.h"
 
 typedef struct _CdCache {
