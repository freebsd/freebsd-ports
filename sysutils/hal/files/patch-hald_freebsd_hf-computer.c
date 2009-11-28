--- hald/freebsd/hf-computer.c.orig	2009-07-18 21:22:48.000000000 -0400
+++ hald/freebsd/hf-computer.c	2009-07-18 21:23:51.000000000 -0400
@@ -26,6 +26,7 @@
 #  include <config.h>
 #endif
 
+#include <stdio.h>
 #include <string.h>
 #include <sys/utsname.h>
 
@@ -133,11 +134,11 @@ hf_computer_device_add (void)
   if (PACKAGE_VERSION) {
       int major, minor, micro;
 
-      hal_device_property_set_string (root, "org.freedesktop.Hal.version", PACKAGE_VERSION);
+      hal_device_property_set_string (device, "org.freedesktop.Hal.version", PACKAGE_VERSION);
       if ( sscanf( PACKAGE_VERSION, "%d.%d.%d", &major, &minor, &micro ) == 3 ) {
-	hal_device_property_set_int (root, "org.freedesktop.Hal.version.major", major);
-        hal_device_property_set_int (root, "org.freedesktop.Hal.version.minor", minor);
-        hal_device_property_set_int (root, "org.freedesktop.Hal.version.micro", micro);
+	hal_device_property_set_int (device, "org.freedesktop.Hal.version.major", major);
+        hal_device_property_set_int (device, "org.freedesktop.Hal.version.minor", minor);
+        hal_device_property_set_int (device, "org.freedesktop.Hal.version.micro", micro);
       }
   }
 
