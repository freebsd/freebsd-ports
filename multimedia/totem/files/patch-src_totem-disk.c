--- src/totem-disc.c.orig	Mon Oct 18 14:00:05 2004
+++ src/totem-disc.c	Mon Oct 18 14:00:14 2004
@@ -26,12 +26,34 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
-#include <mntent.h>
 #include <string.h>
 
 #include <sys/ioctl.h>
 #include <sys/stat.h>
+
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
+#define ENOMEDIUM ENODEV
+#define CDROM_GET_CAPABILITY CDIOCCLRDEBUG
+#else
 #include <linux/cdrom.h>
+#include <mntent.h>
+#endif
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -395,8 +417,10 @@
   /* open disc, check capabilities and open mount */
   if (!cd_cache_open_device (cache, error))
     return MEDIA_TYPE_ERROR;
+#ifdef __linux__
   if (!(cache->cap & CDC_DVD))
     return MEDIA_TYPE_DATA;
+#endif
   if (!(dir = cd_cache_open_mountpoint (cache, error)))
     return MEDIA_TYPE_ERROR;
 
