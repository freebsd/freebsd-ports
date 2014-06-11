--- src/wcmISDV4.c~
+++ src/wcmISDV4.c
@@ -24,11 +24,16 @@
 #include "xf86Wacom.h"
 #include <xf86_OSproc.h>
 #include "wcmFilter.h"
-#include <linux/serial.h>
 #include "isdv4.h"
 #include <unistd.h>
 #include <fcntl.h>
+
+#ifdef __linux__
+#include <linux/serial.h>
 #include <libudev.h>
+#else
+#include <termios.h>
+#endif
 
 #define RESET_RELATIVE(ds) do { (ds).relwheel = 0; } while (0)
 
@@ -192,10 +197,15 @@ static int wcmSerialValidate(InputInfoPt
 
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
 
@@ -959,6 +969,7 @@ static Bool get_keys_vendor_tablet_id(ch
 	return TRUE;
 }
 
+#ifdef __linux__
 /**
  * Return the content of id file from sysfs:  /sys/.../device/id
  *
@@ -1004,6 +1015,7 @@ out:
 
 	return ret;
 }
+#endif
 
 /**
  * Query the device's fd for the key bits and the tablet ID. Returns the ID
@@ -1018,11 +1030,16 @@ out:
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
@@ -1037,9 +1054,11 @@ static int isdv4ProbeKeys(InputInfoPtr p
 	common->wcmProtocolLevel = WCM_PROTOCOL_GENERIC;
 
 	if (!get_keys_vendor_tablet_id(pInfo->name, common)) {
+#ifdef __linux__
 		char buf[15] = {0};
 		if (get_sysfs_id(pInfo, buf, sizeof(buf)))
 			get_keys_vendor_tablet_id(buf, common);
+#endif
 	}
 
 	return common->tablet_id;
