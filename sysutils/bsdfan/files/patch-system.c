--- system.c.orig	2018-01-12 16:11:08 UTC
+++ system.c
@@ -10,7 +10,7 @@
 #include "system.h"
 
 #define INVALID_MODE_ERROR "Invalid fan mode"
-#define PERMISSION_ERROR "Not enough permissions"
+#define FAN_SYSCTL_NODE "dev.acpi_ibm.0.fan"
 #define KELVIN_TO_CELSIUS(t) ((t-2732+5)/10)
 
 static int idx_cur_level;
@@ -30,8 +30,8 @@ setFan(int mode, const struct Level *levels)
 	case MANUAL:
 	case AUTO:
 		/*set fan in manual mode*/
-		if (sysctlbyname("dev.acpi_ibm.0.fan",NULL,NULL,&mode,sizeof(int)) == -1)
-			err(EX_NOPERM, PERMISSION_ERROR);
+		if (sysctlbyname(FAN_SYSCTL_NODE,NULL,NULL,&mode,sizeof(int)) == -1)
+			err(EX_NOPERM, FAN_SYSCTL_NODE);
 
 		if (mode == AUTO)
 			break;
@@ -86,7 +86,7 @@ levelDown(const struct Level *levels)
 }
 
 int
-getTemp()
+getTemp(void)
 {
 	int temp[8]={0};
 	size_t len = 8*sizeof(int);
