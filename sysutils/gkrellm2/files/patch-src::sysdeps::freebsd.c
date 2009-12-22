Index: src/sysdeps/freebsd.c
diff -u -p src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	2008-10-29 07:15:43.000000000 +0900
+++ src/sysdeps/freebsd.c	2009-12-22 19:07:46.422456219 +0900
@@ -1041,7 +1041,7 @@ gkrellm_sys_mem_read_data(void)
 	static gint	swappgsin = -1;
 	static gint	swappgsout = -1;
 	gint		dpagein, dpageout;
-	guint64		total, used, x_used, free, shared, buffers, cached;
+	guint64		total, used, x_used, free, shared, buffers = 0, cached;
 	struct vmtotal	vmt;
 	size_t		length_vmt = sizeof(vmt);
 	static int	oid_vmt[] = { CTL_VM, VM_TOTAL };
@@ -1380,6 +1380,7 @@ static VoltDefault	voltdefault0[] =
 #define INTERFACE_SMB		1
 #define INTERFACE_ACPI		2
 #define INTERFACE_CORETEMP	3		/* Already in Celsius */
+#define INTERFACE_AMDTEMP	4
 
 /* Addresses to use for /dev/io */
 #define WBIO1			0x295
@@ -1448,23 +1449,15 @@ gkrellm_sys_sensors_get_temperature(gcha
 		return gkrellm_sys_sensors_mbmon_get_value(path, temp);
 		}
 
-	if (interface == INTERFACE_ACPI)
+	if (interface == INTERFACE_ACPI || interface == INTERFACE_CORETEMP ||
+	    interface == INTERFACE_AMDTEMP)
 		{
 		size = sizeof(value);
 		if (sysctlbyname(path, &value, &size, NULL, 0) < 0)
 			return FALSE;
 		if (temp)
-			*temp = (gfloat) TZ_KELVTOC(value);
-		return TRUE;
-		}
-
-	if (interface == INTERFACE_CORETEMP)
-		{
-		size = sizeof(value);
-		if (sysctlbyname(path, &value, &size, NULL, 0) < 0)
-			return FALSE;
-		if (temp)
-			*temp = (gfloat) value;
+			*temp = (interface == INTERFACE_CORETEMP) ?
+				(gfloat) value : (gfloat) TZ_KELVTOC(value);
 		return TRUE;
 		}
 
@@ -1537,10 +1530,10 @@ static GList	*freebsd_sensor_list;
 gboolean
 gkrellm_sys_sensors_init(void)
 	{
-	gchar		mib_name[256], label[8];
+	gchar		mib_name[256], label[8], buf[BUFSIZ], *fmt;
 	gint		interface, id;
-	int		oid_acpi_temp[CTL_MAXNAME + 2];
-	size_t		oid_acpi_temp_len;
+	int		oid[CTL_MAXNAME + 2];
+	size_t		oid_len, len;
 	GList		*list;
 	struct freebsd_sensor *sensor;
 
@@ -1553,9 +1546,8 @@ gkrellm_sys_sensors_init(void)
 		{
 		snprintf(mib_name, sizeof(mib_name),
 			 "hw.acpi.thermal.tz%d.temperature", id);
-		oid_acpi_temp_len = sizeof(oid_acpi_temp);
-		if (gk_sysctlnametomib(mib_name, oid_acpi_temp,
-				       &oid_acpi_temp_len) < 0)
+		oid_len = sizeof(oid);
+		if (gk_sysctlnametomib(mib_name, oid, &oid_len) < 0)
 			break;
 		interface = INTERFACE_ACPI;
 		if (!gkrellm_sys_sensors_get_temperature(mib_name, 0, 0,
@@ -1567,16 +1559,22 @@ gkrellm_sys_sensors_init(void)
 					   interface, 1.0, 0.0, NULL, label);
 		}
 
-	/* Coretemp */
+	/* Coretemp and Amdtemp */
 	for (id = 0;; id++)
 		{
 		snprintf(mib_name, sizeof(mib_name),
 			 "dev.cpu.%d.temperature", id);
-		oid_acpi_temp_len = sizeof(oid_acpi_temp);
-		if (gk_sysctlnametomib(mib_name, oid_acpi_temp,
-				       &oid_acpi_temp_len) < 0)
+		oid_len = sizeof(oid) - sizeof(int) * 2;
+		if (gk_sysctlnametomib(mib_name, oid + 2, &oid_len) < 0)
+			break;
+		oid[0] = 0;
+		oid[1] = 4;
+		len = sizeof(buf);
+		if (sysctl(oid, oid_len + 2, buf, &len, 0, 0) < 0)
 			break;
-		interface = INTERFACE_CORETEMP;
+		fmt = (gchar *)(buf + sizeof(u_int));
+		interface = (fmt[1] == 'K') ?
+			INTERFACE_AMDTEMP : INTERFACE_CORETEMP;
 		if (!gkrellm_sys_sensors_get_temperature(mib_name, 0, 0,
 							 interface, NULL))
 			continue;
