--- src/freebsd.cc.orig	2016-10-04 07:49:19 UTC
+++ src/freebsd.cc
@@ -426,13 +426,15 @@ double get_acpi_temperature(int fd)
 	int temp;
 	(void)fd;
 
-	if (GETSYSCTL("hw.acpi.thermal.tz0.temperature", temp)) {
-		fprintf(stderr,
-			"Cannot read sysctl \"hw.acpi.thermal.tz0.temperature\"\n");
-		return 0.0;
-	}
+	if (GETSYSCTL("hw.acpi.thermal.tz0.temperature", temp) == 0)
+		return KELVTOC(temp);
+	if (GETSYSCTL("dev.cpu.0.temperature", temp) == 0)
+		return KELVTOC(temp);
+	if (GETSYSCTL("dev.amdtemp.0.core0.sensor0", temp) == 0)
+		return KELVTOC(temp);
+	fprintf(stderr, "Cannot get temperature from sysctl\n");
 
-	return KELVTOC(temp);
+	return 0.0;
 }
 
 static void get_battery_stats(int *battime, int *batcapacity, int *batstate, int *ac) {
