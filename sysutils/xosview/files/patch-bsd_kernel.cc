--- bsd/kernel.cc.orig	2021-05-16 03:48:22 UTC
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
@@ -1558,6 +1560,7 @@ BSDHasBattery() {
 #else // XOSVIEW_FREEBSD || XOSVIEW_DFBSD
 	int fd;
 	if ( (fd = open(ACPIDEV, O_RDONLY)) == -1 ) {
+		#if defined(__amd64__) || defined(__i386__)
 		// No ACPI -> try APM
 		if ( (fd = open(APMDEV, O_RDONLY)) == -1 )
 			return false;
@@ -1569,6 +1572,9 @@ BSDHasBattery() {
 		if (aip.ai_batt_stat == 0xff || aip.ai_batt_life == 0xff)
 			return false;
 		return true;
+		#else
+		return false;
+		#endif
 	}
 
 	union acpi_battery_ioctl_arg battio;
@@ -1717,6 +1723,7 @@ BSDGetBatteryInfo(int *remaining, unsigned int *state)
 	/* Adapted from acpiconf and apm. */
 	int fd;
 	if ( (fd = open(ACPIDEV, O_RDONLY)) == -1 ) {
+		#if defined(__amd64__) || defined(__i386__)
 		// No ACPI -> try APM
 		if ( (fd = open(APMDEV, O_RDONLY)) == -1 )
 			err(EX_OSFILE, "could not open %s or %s", ACPIDEV, APMDEV);
@@ -1740,6 +1747,10 @@ BSDGetBatteryInfo(int *remaining, unsigned int *state)
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
