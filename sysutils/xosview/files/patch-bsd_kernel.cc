--- bsd/kernel.cc.orig	2020-07-11 12:10:34 UTC
+++ bsd/kernel.cc
@@ -48,8 +48,10 @@ static int maxcpus = 1;
 #include <sys/ioctl.h>
 #include <sys/resource.h>
 #include <dev/acpica/acpiio.h>
+#if defined(__amd64__) || defined(__i386__)
 #include <machine/apm_bios.h>
 #endif
+#endif
 
 #if defined(XOSVIEW_NETBSD)
 #include <sys/sched.h>
@@ -338,15 +340,14 @@ BSDGetPageStats(uint64_t *meminfo, uint64_t *pageinfo)
 		u_int v_swappgsout;
 	} vm;
 #if defined(XOSVIEW_FREEBSD)
-	size_t size = sizeof(unsigned int);
+	size_t size = sizeof(u_int);
+	bzero(&vm, sizeof(vm));
 #define	GET_VM_STATS(name) \
 	sysctlbyname("vm.stats.vm." #name, &vm.name, &size, NULL, 0)
 	GET_VM_STATS(v_active_count);
 	GET_VM_STATS(v_inactive_count);
 	GET_VM_STATS(v_wire_count);
-#if __FreeBSD_version < 1200017
 	GET_VM_STATS(v_cache_count);
-#endif
 	GET_VM_STATS(v_free_count);
 	GET_VM_STATS(v_page_size);
 	GET_VM_STATS(v_vnodepgsin);
@@ -368,9 +369,7 @@ BSDGetPageStats(uint64_t *meminfo, uint64_t *pageinfo)
 		meminfo[0] = (uint64_t)vm.v_active_count * vm.v_page_size;
 		meminfo[1] = (uint64_t)vm.v_inactive_count * vm.v_page_size;
 		meminfo[2] = (uint64_t)vm.v_wire_count * vm.v_page_size;
-#if __FreeBSD_version < 1200017
 		meminfo[3] = (uint64_t)vm.v_cache_count * vm.v_page_size;
-#endif
 		meminfo[4] = (uint64_t)vm.v_free_count * vm.v_page_size;
 #else  /* XOSVIEW_DFBSD */
 		meminfo[0] = (uint64_t)vms.v_active_count * vms.v_page_size;
@@ -1558,6 +1557,7 @@ BSDHasBattery() {
 #else // XOSVIEW_FREEBSD || XOSVIEW_DFBSD
 	int fd;
 	if ( (fd = open(ACPIDEV, O_RDONLY)) == -1 ) {
+		#if defined(__amd64__) || defined(__i386__)
 		// No ACPI -> try APM
 		if ( (fd = open(APMDEV, O_RDONLY)) == -1 )
 			return false;
@@ -1569,6 +1569,9 @@ BSDHasBattery() {
 		if (aip.ai_batt_stat == 0xff || aip.ai_batt_life == 0xff)
 			return false;
 		return true;
+		#else
+		return false;
+		#endif
 	}
 
 	union acpi_battery_ioctl_arg battio;
@@ -1717,6 +1720,7 @@ BSDGetBatteryInfo(int *remaining, unsigned int *state)
 	/* Adapted from acpiconf and apm. */
 	int fd;
 	if ( (fd = open(ACPIDEV, O_RDONLY)) == -1 ) {
+		#if defined(__amd64__) || defined(__i386__)
 		// No ACPI -> try APM
 		if ( (fd = open(APMDEV, O_RDONLY)) == -1 )
 			err(EX_OSFILE, "could not open %s or %s", ACPIDEV, APMDEV);
@@ -1740,6 +1744,10 @@ BSDGetBatteryInfo(int *remaining, unsigned int *state)
 		else
 			*state = XOSVIEW_BATT_NONE;
 		return;
+		#else
+		*state = XOSVIEW_BATT_NONE;
+		return;
+		#endif
 	}
 	// ACPI
 	union acpi_battery_ioctl_arg battio;
