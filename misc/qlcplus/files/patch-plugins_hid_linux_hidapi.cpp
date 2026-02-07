--- plugins/hid/linux/hidapi.cpp.orig	2023-06-30 08:12:36 UTC
+++ plugins/hid/linux/hidapi.cpp
@@ -38,9 +38,15 @@
 #include <poll.h>
 
 /* Linux */
+#ifdef __FreeBSD__
+typedef uint32_t __u32;
+#include <dev/hid/hid.h>
+#include <dev/hid/hidraw.h>
+#else
 #include <linux/hidraw.h>
 #include <linux/version.h>
 #include <linux/input.h>
+#endif
 #include <libudev.h>
 
 #include "hidapi.h"
