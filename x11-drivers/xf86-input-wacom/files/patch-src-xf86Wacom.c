--- src/xf86Wacom.c.orig	2015-10-23 17:26:33 UTC
+++ src/xf86Wacom.c
@@ -667,6 +667,17 @@ void wcmReadPacket(InputInfoPtr pInfo)
 
 	if (len <= 0)
 	{
+		/* BSD specific code. */
+		/* Hotplug code does not send remove dev notify because
+		 * opened cuse dev cant be removed. */
+		if (priv->isParent && errno == EINVAL) {
+			WacomDevicePtr other;
+			for (other = common->wcmDevices; other; other = other->next) {
+				xf86Msg(X_INFO, "%s: removing automatically added device.\n",
+					other->pInfo->name);
+				DeleteInputDeviceRequest(other->pInfo->dev);
+			}
+		} else
 		/* for all other errors, hope that the hotplugging code will
 		 * remove the device */
 		if (errno != EAGAIN && errno != EINTR)
