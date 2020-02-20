* Include devd in the set of config backends
*
--- hw/xfree86/common/xf86Globals.c.orig	2017-03-15 18:05:25 UTC
+++ hw/xfree86/common/xf86Globals.c
@@ -119,7 +119,8 @@ xf86InfoRec xf86Info = {
     .miscModInDevEnabled = TRUE,
     .miscModInDevAllowNonLocal = FALSE,
     .pmFlag = TRUE,
-#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS)
+#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS) || \
+	defined(CONFIG_DEVD)
     .forceInputDevices = FALSE,
     .autoAddDevices = TRUE,
     .autoEnableDevices = TRUE,
