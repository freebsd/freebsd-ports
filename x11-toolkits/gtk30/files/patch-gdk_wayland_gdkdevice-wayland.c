--- gdk/wayland/gdkdevice-wayland.c.orig	2018-03-25 16:25:12 UTC
+++ gdk/wayland/gdkdevice-wayland.c
@@ -38,11 +38,9 @@
 
 #include <xkbcommon/xkbcommon.h>
 
-#include <linux/input.h>
-
 #include <sys/time.h>
 #include <sys/mman.h>
-#include <linux/input.h>
+#include <dev/evdev/input.h>
 
 #define BUTTON_BASE (BTN_LEFT - 1) /* Used to translate to 1-indexed buttons */
 
