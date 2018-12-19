--- src/wcmISDV4.c.orig	2017-05-30 18:42:52 UTC
+++ src/wcmISDV4.c
@@ -24,14 +24,19 @@
 #include "xf86Wacom.h"
 #include <xf86_OSproc.h>
 #include "wcmFilter.h"
-#include <linux/serial.h>
 #include "isdv4.h"
 #include <unistd.h>
 #include <fcntl.h>
-#include <libudev.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#ifdef __linux__
+#include <linux/serial.h>
+#include <libudev.h>
+#else
+#include <termios.h>
+#endif
+
 #define RESET_RELATIVE(ds) do { (ds).relwheel = 0; } while (0)
 
 /* resolution in points/m */
@@ -195,10 +200,15 @@ static int wcmSerialValidate(InputInfoPtr pInfo, const
 
 static Bool isdv4Detect(InputInfoPtr pInfo)
 {
-	struct serial_struct ser;
 	int rc;
 
+#ifdef __linux__
+	struct serial_struct ser;
 	rc = ioctl(pInfo->fd, TIOCGSERIAL, &ser);
+#else
+	struct termios termAttr;
+	rc = tcgetattr(pInfo->fd, &termAttr);
+#endif
 	if (rc == -1)
 		return FALSE;
 
@@ -968,6 +978,7 @@ static Bool get_keys_vendor_tablet_id(char *name, Waco
 	return TRUE;
 }
 
+#ifdef __linux__
 /**
  * Return the content of id file from sysfs:  /sys/.../device/id
  *
@@ -1017,6 +1028,7 @@ out:
 
 	return ret;
 }
+#endif
 
 /**
  * Query the device's fd for the key bits and the tablet ID. Returns the ID
@@ -1031,11 +1043,16 @@ out:
  */
 static int isdv4ProbeKeys(InputInfoPtr pInfo)
 {
-	struct serial_struct tmp;
 	WacomDevicePtr  priv = (WacomDevicePtr)pInfo->private;
 	WacomCommonPtr  common = priv->common;
 
+#ifdef __linux__
+	struct serial_struct tmp;
 	if (ioctl(pInfo->fd, TIOCGSERIAL, &tmp) < 0)
+#else
+	struct termios tmp;
+	if (tcgetattr(pInfo->fd, &tmp) < 0)
+#endif
 		return 0;
 
 	common->tablet_id = 0x90;
@@ -1050,9 +1067,11 @@ static int isdv4ProbeKeys(InputInfoPtr pInfo)
 	common->wcmProtocolLevel = WCM_PROTOCOL_GENERIC;
 
 	if (!get_keys_vendor_tablet_id(pInfo->name, common)) {
+#ifdef __linux__
 		char buf[15] = {0};
 		if (get_sysfs_id(pInfo, buf, sizeof(buf)))
 			get_keys_vendor_tablet_id(buf, common);
+#endif
 	}
 
 	return common->tablet_id;
