Index: src/sysdeps/freebsd.c
diff -u -p src/sysdeps/freebsd.c.orig src/sysdeps/freebsd.c
--- src/sysdeps/freebsd.c.orig	2007-07-07 08:53:07.000000000 +0900
+++ src/sysdeps/freebsd.c	2008-01-31 16:47:46.328923081 +0900
@@ -97,7 +97,7 @@ void
 gkrellm_sys_cpu_read_data(void)
 	{
 	long		cp_time[CPUSTATES];
-	int		len = sizeof(cp_time);
+	size_t		len = sizeof(cp_time);
 	static struct nlist nl[] = {
 #define N_CP_TIME	0
 		{ "_cp_time" },
@@ -206,7 +206,7 @@ gkrellm_sys_proc_read_data(void)
 	static u_int	n_processes, n_forks = 0, curpid = -1;
 	u_int		n_vforks, n_rforks;
 	gint		r_forks, r_vforks, r_rforks;
-	gint		len;
+	size_t		len;
 	gint		nextpid, nforked;
 	static struct nlist nl[] = {
 #define N_NEXTPID	0
@@ -570,7 +570,7 @@ gkrellm_sys_inet_read_tcp_data(void)
 	gint		tcp_status;
 	struct xinpgen	*xig, *oxig;
 	gchar		*buf;
-	gint		len = 0;
+	size_t		len = 0;
 
 	if (!initialized)
 		{
@@ -680,7 +680,7 @@ extern	kvm_t	*kvmd;
 extern	char	errbuf[];
 
 static int
-swapmode(guint64 *retavail, guint64 *retfree)
+swapmode(unsigned long long *retavail, unsigned long long *retfree)
 	{
 	guint64 used, avail;
 #if  __FreeBSD_version >= 400000
@@ -930,9 +930,9 @@ static struct mibtab mibs[] = {
 #endif
 
 static guint64	swapin,
-		swapout,
-		swap_total,
-		swap_used;
+		swapout;
+static unsigned long long	swap_total,
+				swap_used;
 
 void
 gkrellm_sys_mem_read_data(void)
@@ -1078,8 +1078,9 @@ gkrellm_sys_mem_init(void)
 /* ===================================================================== */
 /* Battery monitor interface */
 
-#if defined(__i386__)
+#if defined(__i386__) || defined(__amd64__)
 #include <osreldate.h>
+#if defined(__i386__)
 #include <machine/apm_bios.h>
 #define	APMDEV		"/dev/apm"
 
@@ -1087,6 +1088,7 @@ gkrellm_sys_mem_init(void)
 #define	L_ON_LINE		1
 #define	L_CHARGING		3
 #define L_UNKNOWN		0xFF
+#endif
 
 /* following two definitions are taken from sys/dev/acpica/acpiio.h */
 #define ACPI_BATT_STAT_CHARGING		0x0002
@@ -1113,16 +1115,18 @@ gkrellm_sys_battery_read_data(void)
 	size_t		size;
 	int		acpi_info[4];
 	int		i;
+#if defined(__i386__)
 	int		f, r;
 	struct apm_info	info;
+	gint		batt_num = 0;
+#endif
 	gboolean	available, on_line, charging;
 	gint		percent, time_left;
-	gint		batt_num = 0;
 
 	if (!first_time_done)
 		{
 		first_time_done = TRUE;
-#ifdef ACPI_SUPPORTS_MULTIPLE_BATTERIES
+#if defined(ACPI_SUPPORTS_MULTIPLE_BATTERIES) || defined(__amd64__)
 		/*
 		 * XXX: Disable getting battery information via ACPI
 		 * to support multiple batteries via APM sim until
@@ -1162,6 +1166,7 @@ gkrellm_sys_battery_read_data(void)
 			return;
 		}
 
+#if defined(__i386__)
 	if ((f = open(APMDEV, O_RDONLY)) == -1)
 		return;
 	if ((r = ioctl(f, APMIO_GETINFO, &info)) == -1) {
@@ -1219,6 +1224,7 @@ gkrellm_sys_battery_read_data(void)
 #endif
 
 	close(f);
+#endif
 	}
 
 gboolean
@@ -1286,6 +1292,7 @@ static VoltDefault	voltdefault0[] =
 #define INTERFACE_IO		0
 #define INTERFACE_SMB		1
 #define INTERFACE_ACPI		2
+#define INTERFACE_CORETEMP	3		/* Already in Celsius */
 
 /* Addresses to use for /dev/io */
 #define WBIO1			0x295
@@ -1319,7 +1326,7 @@ get_data(int iodev, u_char command, int 
 		struct smbcmd cmd;
 
 		bzero(&cmd, sizeof(cmd));
-		cmd.data.byte_ptr = &byte;
+		cmd.data.byte_ptr = (char *)&byte;
 		cmd.slave         = 0x5a;
 		cmd.cmd           = command;
 		if (ioctl(iodev, SMB_READB, (caddr_t)&cmd) == -1)
@@ -1345,6 +1352,8 @@ gkrellm_sys_sensors_get_temperature(gcha
 
 	{
 	u_char byte;
+	int value;
+	size_t size;
 
 	if (interface == MBMON_INTERFACE)
 		{
@@ -1354,15 +1363,24 @@ gkrellm_sys_sensors_get_temperature(gcha
 
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
@@ -1435,7 +1453,7 @@ gkrellm_sys_sensors_init(void)
 	gchar		mib_name[256], label[8];
 	gint		interface, id;
 	int		oid_acpi_temp[CTL_MAXNAME + 2];
-	size_t		oid_acpi_temp_len = sizeof(oid_acpi_temp);
+	size_t		oid_acpi_temp_len;
 	GList		*list;
 	struct freebsd_sensor *sensor;
 
@@ -1443,10 +1461,12 @@ gkrellm_sys_sensors_init(void)
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
@@ -1458,7 +1478,27 @@ gkrellm_sys_sensors_init(void)
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
