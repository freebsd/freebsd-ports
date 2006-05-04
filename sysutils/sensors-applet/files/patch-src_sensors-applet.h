--- src/sensors-applet.h.orig	Fri Mar 24 15:44:07 2006
+++ src/sensors-applet.h	Thu May  4 04:58:05 2006
@@ -32,41 +32,28 @@
 #define CPU_ICON PIXMAPS_DIR "cpu-icon.png"
 #define HDD_ICON PIXMAPS_DIR "hdd-icon.png"
 #define BATTERY_ICON PIXMAPS_DIR "battery-icon.png"
-#define MEM_ICON PIXMAPS_DIR "mem-icon.png"
+#define MEM_ICON PIXMAPS_DIR "memory-icon.png"
 #define GPU_ICON PIXMAPS_DIR "gpu-icon.png"
 #define GENERIC_ICON PIXMAPS_DIR "generic-icon.png"
 #define FAN_ICON PIXMAPS_DIR "fan-icon.png"
+#define CASE_ICON PIXMAPS_DIR "case-icon.png"
 #define VOLTAGE_ICON NULL
 
 #define DEFAULT_ICON_SIZE 24
 
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
+	SMARTCTL,
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
+	"mbmon",
+	"smartctl"
 };
 
 /* enumeration used to identify columns in the GtkTreeStore data
