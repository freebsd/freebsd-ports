--- hw/xfree86/common/xf86Globals.c.orig	2014-04-12 15:29:14 UTC
+++ hw/xfree86/common/xf86Globals.c
@@ -123,7 +123,8 @@ xf86InfoRec xf86Info = {
     .log = LogNone,
     .disableRandR = FALSE,
     .randRFrom = X_DEFAULT,
-#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS)
+#if defined(CONFIG_HAL) || defined(CONFIG_UDEV) || defined(CONFIG_WSCONS) || \
+	defined(CONFIG_DEVD)
     .forceInputDevices = FALSE,
     .autoAddDevices = TRUE,
     .autoEnableDevices = TRUE,
