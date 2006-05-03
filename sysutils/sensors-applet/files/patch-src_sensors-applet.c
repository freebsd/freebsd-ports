--- src/sensors-applet.c.orig	Fri Mar 24 15:42:32 2006
+++ src/sensors-applet.c	Wed May  3 22:07:12 2006
@@ -29,22 +29,13 @@
 #include "sensors-applet.h"
 #include "active-sensor.h"
 #include "sensors-applet-gconf.h"
-#include "acpi-sensors-interface.h"
 
 /* use libsensors if available, otherwise manually find sensors */
 #ifdef HAVE_LIBSENSORS
 #include "libsensors-sensors-interface.h"
-#else
-#include "i2c-sys-sensors-interface.h"
-#include "i2c-proc-sensors-interface.h"
 #endif
 
-#include "i8k-sensors-interface.h"
-#include "ibm-acpi-sensors-interface.h"
-#include "omnibook-sensors-interface.h"
-#include "pmu-sys-sensors-interface.h"
-#include "smu-sys-sensors-interface.h"
-#include "hddtemp-sensors-interface.h"
+#include "mbmon-sensors-interface.h"
 #include "prefs-dialog.h"
 #include "about-dialog.h"
 
@@ -754,19 +745,10 @@
 }
 
 static void sensors_applet_setup_sensors_interfaces(SensorsApplet *sensors_applet) {
-	acpi_sensors_interface_init(sensors_applet);
-	hddtemp_sensors_interface_init(sensors_applet);
 #ifdef HAVE_LIBSENSORS
 	libsensors_sensors_interface_init(sensors_applet);
-#else
-	i2c_proc_sensors_interface_init(sensors_applet);
-	i2c_sys_sensors_interface_init(sensors_applet);
 #endif
-	i8k_sensors_interface_init(sensors_applet);
-	ibm_acpi_sensors_interface_init(sensors_applet);
-	omnibook_sensors_interface_init(sensors_applet);
-	pmu_sys_sensors_interface_init(sensors_applet);
-	smu_sys_sensors_interface_init(sensors_applet);
+	mbmon_sensors_interface_init(sensors_applet);
 }
 
 
