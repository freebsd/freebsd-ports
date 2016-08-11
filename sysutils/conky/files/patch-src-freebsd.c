--- src/freebsd.c.orig	2012-05-03 21:08:27 UTC
+++ src/freebsd.c
@@ -283,11 +283,7 @@ int update_running_processes(void)
 	pthread_mutex_lock(&kvm_proc_mutex);
 	p = kvm_getprocs(kd, KERN_PROC_ALL, 0, &n_processes);
 	for (i = 0; i < n_processes; i++) {
-#if (__FreeBSD__ < 5) && (__FreeBSD_kernel__ < 5)
-		if (p[i].kp_proc.p_stat == SRUN) {
-#else
 		if (p[i].ki_stat == SRUN) {
-#endif
 			cnt++;
 		}
 	}
@@ -464,7 +460,7 @@ void get_battery_stuff(char *buf, unsign
 			break;
 		case BATTERY_STATUS:
 			if (batstate == 1) // Discharging
-				snprintf(buf, n, "remaining %d%%", batcapacity);
+				snprintf(buf, n, "remaining (%d%%)", batcapacity);
 			else
 				snprintf(buf, n, batstate == 2 ? "charging (%d%%)" :
 						(batstate == 7 ? "absent/on AC" : "charged (%d%%)"),
@@ -497,26 +493,10 @@ static int check_bat(const char *bat)
 
 int get_battery_perct(const char *bat)
 {
-	union acpi_battery_ioctl_arg battio;
-	int batnum, acpifd;
-	int designcap, lastfulcap, batperct;
+	int batcapacity;
 
-	if ((battio.unit = batnum = check_bat(bat)) < 0)
-		return 0;
-	if ((acpifd = open("/dev/acpi", O_RDONLY)) < 0) {
-		fprintf(stderr, "Can't open ACPI device\n");
-		return 0;
-	}
-	if (ioctl(acpifd, ACPIIO_BATT_GET_BIF, &battio) == -1) {
-		fprintf(stderr, "Unable to get info for battery unit %d\n", batnum);
-		return 0;
-	}
-	close(acpifd);
-	designcap = battio.bif.dcap;
-	lastfulcap = battio.bif.lfcap;
-	batperct = (designcap > 0 && lastfulcap > 0) ?
-		(int) (((float) lastfulcap / designcap) * 100) : 0;
-	return batperct > 100 ? 100 : batperct;
+	get_battery_stats(NULL, &batcapacity, NULL, NULL);
+	return batcapacity;
 }
 
 int get_battery_perct_bar(const char *bar)
@@ -970,11 +950,14 @@ void get_battery_short_status(char *buff
 	if (0 == strncmp("charging", buffer, 8)) {
 		buffer[0] = 'C';
 		memmove(buffer + 1, buffer + 8, n - 8);
-	} else if (0 == strncmp("discharging", buffer, 11)) {
+	} else if (0 == strncmp("remaining", buffer, 9)) {
 		buffer[0] = 'D';
-		memmove(buffer + 1, buffer + 11, n - 11);
+		memmove(buffer + 1, buffer + 9, n - 9);
+	} else if (0 == strncmp("charged", buffer, 7)) {
+		buffer[0] = 'F';
+		memmove(buffer + 1, buffer + 7, n - 7);
 	} else if (0 == strncmp("absent/on AC", buffer, 12)) {
-		buffer[0] = 'A';
+		buffer[0] = 'N';
 		memmove(buffer + 1, buffer + 12, n - 12);
 	}
 }
