Index: src/sysdeps/freebsd.c
diff -u -p src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	2007-07-07 08:53:07.000000000 +0900
+++ src/sysdeps/freebsd.c	2007-12-24 20:26:19.000000000 +0900
@@ -1286,6 +1286,7 @@ static VoltDefault	voltdefault0[] =
 #define INTERFACE_IO		0
 #define INTERFACE_SMB		1
 #define INTERFACE_ACPI		2
+#define INTERFACE_CORETEMP	3		/* Already in Celsius */
 
 /* Addresses to use for /dev/io */
 #define WBIO1			0x295
@@ -1345,6 +1346,8 @@ gkrellm_sys_sensors_get_temperature(gcha
 
 	{
 	u_char byte;
+	int value;
+	size_t size;
 
 	if (interface == MBMON_INTERFACE)
 		{
@@ -1354,15 +1357,24 @@ gkrellm_sys_sensors_get_temperature(gcha
 
 	if (interface == INTERFACE_ACPI)
 		{
-		int value;
-		size_t size = sizeof(value);
-
+		size = sizeof(value);
 		if (sysctlbyname(path, &value, &size, NULL, 0) < 0)
 			return FALSE;
 		if (temp)
 			*temp = (gfloat) TZ_KELVTOC(value);
 		return TRUE;
 		}
+
+	if (interface == INTERFACE_CORETEMP)
+		{
+		size = sizeof(value);
+		if (sysctlbyname(path, &value, &size, NULL, 0) < 0)
+			return FALSE;
+		if (temp)
+			*temp = (gfloat) value;
+		return TRUE;
+		}
+
 	if (get_data(iodev, LM78_TEMP, interface, &byte))
 		{
 		if (temp)
@@ -1435,7 +1447,7 @@ gkrellm_sys_sensors_init(void)
 	gchar		mib_name[256], label[8];
 	gint		interface, id;
 	int		oid_acpi_temp[CTL_MAXNAME + 2];
-	size_t		oid_acpi_temp_len = sizeof(oid_acpi_temp);
+	size_t		oid_acpi_temp_len;
 	GList		*list;
 	struct freebsd_sensor *sensor;
 
@@ -1443,10 +1455,12 @@ gkrellm_sys_sensors_init(void)
 	*/
 	gkrellm_sys_sensors_mbmon_check(TRUE);
 
-	for (id = 0;;)
-	{
+	/* ACPI Thermal */
+	for (id = 0;; id++)
+		{
 		snprintf(mib_name, sizeof(mib_name),
 			 "hw.acpi.thermal.tz%d.temperature", id);
+		oid_acpi_temp_len = sizeof(oid_acpi_temp);
 		if (gk_sysctlnametomib(mib_name, oid_acpi_temp,
 				       &oid_acpi_temp_len) < 0)
 			break;
@@ -1458,7 +1472,27 @@ gkrellm_sys_sensors_init(void)
 		gkrellm_sensors_add_sensor(SENSOR_TEMPERATURE, NULL,
 					   mib_name, 0, 0,
 					   interface, 1.0, 0.0, NULL, label);
-	}
+		}
+
+	/* Coretemp */
+	for (id = 0;; id++)
+		{
+		snprintf(mib_name, sizeof(mib_name),
+			 "dev.cpu.%d.temperature", id);
+		oid_acpi_temp_len = sizeof(oid_acpi_temp);
+		if (gk_sysctlnametomib(mib_name, oid_acpi_temp,
+				       &oid_acpi_temp_len) < 0)
+			break;
+		interface = INTERFACE_CORETEMP;
+		if (!gkrellm_sys_sensors_get_temperature(mib_name, 0, 0,
+							 interface, NULL))
+			continue;
+		snprintf(label, sizeof(label), "cpu%d", id);
+		gkrellm_sensors_add_sensor(SENSOR_TEMPERATURE, NULL,
+					   mib_name, 0, 0,
+					   interface, 1.0, 0.0, NULL, label);
+		}
+
 
 	if (freebsd_sensor_list)
 		{
