--- src/sensors-applet.h.orig	Fri Mar 24 15:44:07 2006
+++ src/sensors-applet.h	Wed May  3 22:07:18 2006
@@ -42,31 +42,15 @@
 
 typedef enum {
 	UNUSED = 0, /* as a flag to test against later */
-	ACPI,
-	HDDTEMP,
-	I2C_SYS,
-	I2C_PROC,
-	IBM_ACPI,
-	I8K,
 	LIBSENSORS,
-	OMNIBOOK,
-	PMU_SYS,
-	SMU_SYS,
+	MBMON,
 	N_SENSOR_INTERFACES
 } SensorInterface;
 
 static const gchar *sensor_interface[] = {
 	"unused",
-	"acpi",
-	"hddtemp",
-	"i2c-sys",
-	"i2c-proc",
-	"ibm-acpi",
-	"i8k",
 	"libsensors",
-	"omnibook",
-	"pmu-sys",
-	"smu-sys",
+	"mbmon"
 };
 
 /* enumeration used to identify columns in the GtkTreeStore data
