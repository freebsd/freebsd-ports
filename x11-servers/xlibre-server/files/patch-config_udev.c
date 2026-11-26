* Don't pass the device parameter when using kbdmux to prevent conflict
*
* Specify a driver to use for basic devices (keyboard and mouse), otherwise none attaches
*
--- config/udev.c.orig	2017-03-15 18:05:25 UTC
+++ config/udev.c
@@ -29,6 +29,7 @@
 
 #include <libudev.h>
 #include <ctype.h>
+#include <fcntl.h>
 #include <unistd.h>
 
 #include "input.h"
@@ -188,7 +189,21 @@ device_added(struct udev_device *udev_de
     char buf[128];
     input_options = input_option_new(input_options, "name", name);
     input_options = input_option_new(input_options, "path", path);
-    input_options = input_option_new(input_options, "device", path);
+    if(strstr(path, "kbdmux") != NULL) {
+        /*
+         * Don't pass "device" option if the keyboard is already attached
+         * to the console (ie. open() fails). This would activate a special
+         * logic in xf86-input-keyboard. Prevent any other attached to console
+         * keyboards being processed. There can be only one such device.
+         */
+        int fd = open(path, O_RDONLY);
+        if (fd > -1) {
+            close(fd);
+            input_options = input_option_new(input_options, "device", path);
+        }
+    }
+    else
+        input_options = input_option_new(input_options, "device", path);
     sprintf(buf, "%u", major(devnum));
     input_options = input_option_new(input_options, "major", buf);
     sprintf(buf, "%u", minor(devnum));
@@ -272,6 +287,18 @@ device_added(struct udev_device *udev_de
         }
     }
 
+    if (attrs.flags & (ATTR_KEY | ATTR_KEYBOARD)) {
+        if (!feature_present("evdev_support"))
+            input_options = input_option_new(input_options, "driver", "kbd");
+    } else if (attrs.flags & ATTR_POINTER) {
+        if (strstr(path, "vbox"))
+            input_options = input_option_new(input_options, "driver", "vboxmouse");
+        else {
+            if (!feature_present("evdev_support"))
+                input_options = input_option_new(input_options, "driver", "mouse");
+        }
+    }
+
     input_options = input_option_new(input_options, "config_info", config_info);
 
     /* Default setting needed for non-seat0 seats */
* [PATCH 2/2] config: udev: fix const issue in strrstr()
* 
* ../config/udev.c: In function ‘strrstr’:
* ../config/udev.c:485:10: error: assignment discards ‘const’ qualifier from pointer target type [-Werror=discarded-qualifiers]
*   485 |     prev = strstr(haystack, needle);
*       |          ^
* 
* Signed-off-by: Enrico Weigelt, metux IT consult <info@metux.net>
--- config/udev.c
+++ config/udev.c
@@ -480,7 +480,7 @@ config_udev_fini(void)
 /* Find the last occurrence of the needle in haystack */
 static char *strrstr(const char *haystack, const char *needle)
 {
-    char *prev, *last, *tmp;
+    const char *prev, *last, *tmp;
 
     prev = strstr(haystack, needle);
     if (!prev)
