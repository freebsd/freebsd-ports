# Finish converting RemoveEnabledDevice to xf86RemoveEnabledDevice
# Finish converting use of Error to ErrorF
# Remove obsolete xf86InputSetScreen
# Correct type of default_options
#
--- src/xf86Fpit.c.orig	2011-06-13 23:24:05 UTC
+++ src/xf86Fpit.c
@@ -251,7 +251,7 @@ static void xf86FpitReadInput(InputInfoP
 	/* Read data into buffer */
 	len = xf86ReadSerial(pInfo->fd, priv->fpitData+priv->fpitIndex, BUFFER_SIZE-priv->fpitIndex);
 	if (len <= 0) {
-		Error("error reading FPIT device");
+		ErrorF("error reading FPIT device\n");
 		priv->fpitIndex = 0;
 		return;
 	}
@@ -324,7 +324,7 @@ static void xf86FpitReadInput(InputInfoP
 		device = pInfo->dev;
 
 		xf86FpitConvert(pInfo, 0, 2, x, y, 0, 0, 0, 0, &conv_x, &conv_y);
-		xf86XInputSetScreen(pInfo, priv->screen_no, conv_x, conv_y);
+		//xf86XInputSetScreen(pInfo, priv->screen_no, conv_x, conv_y);
 
 		/* coordinates are ready we can send events */
 
@@ -459,7 +459,7 @@ static Bool xf86FpitControl(DeviceIntPtr
 		if (pInfo->fd < 0) {
 			pInfo->fd = xf86OpenSerial(pInfo->options);
 			if (pInfo->fd < 0) {
-				Error("Unable to open Fpit touchscreen device");
+				ErrorF("Unable to open Fpit touchscreen device\n");
 				return !Success;
 			}
 
@@ -488,7 +488,7 @@ static Bool xf86FpitControl(DeviceIntPtr
 	case DEVICE_CLOSE:
 		dev->public.on = FALSE;
 		if (pInfo->fd >= 0) {
-			RemoveEnabledDevice(pInfo->fd);
+			xf86RemoveEnabledDevice(pInfo);
 		}
 		xf86CloseSerial(pInfo->fd);
 		pInfo->fd = -1;
@@ -550,7 +550,7 @@ static void xf86FpitUninit(InputDriverPt
 	xf86DeleteInput(pInfo, 0);
 }
 
-static char *default_options[] = {
+static const char *default_options[] = {
 	"BaudRate", "19200", "StopBits", "0", "DataBits", "8", "Parity", "None", "Vmin", "10", "Vtime", "1", "FlowControl", "None", NULL
 };
 
