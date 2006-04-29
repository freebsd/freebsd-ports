--- src/plparse/totem-disc.c.orig	Thu Nov 24 16:53:02 2005
+++ src/plparse/totem-disc.c	Sun Dec 18 13:34:12 2005
@@ -43,7 +43,29 @@
 #include <glib/gi18n.h>
 #include <libgnomevfs/gnome-vfs.h>
 
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
 #include <linux/cdrom.h>
+#endif
 
 #include "totem-disc.h"
 
