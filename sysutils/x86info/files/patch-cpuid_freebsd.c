--- cpuid-freebsd.c.orig	2017-09-06 10:17:13.000000000 -0600
+++ cpuid-freebsd.c	2018-01-11 10:34:01.353720000 -0700
@@ -39,7 +39,7 @@
 	static int nodriver=0;
 	char cpuname[20];
 	int fh;
-	cpuctl_cpuid_args_t args;
+	cpuctl_cpuid_count_args_t args;
 
 	if (nodriver == 1) {
 		if (native_cpuid(CPU_number, idx, eax,ebx,ecx,edx))
@@ -48,11 +48,12 @@
 	}
 
 	args.level = idx;
+	args.level_type = idx >> 32;
 	/* Ok, use the /dev/CPU interface in preference to the _up code. */
 	(void)snprintf(cpuname, sizeof(cpuname), "/dev/cpuctl%u", CPU_number);
 	fh = open(cpuname, O_RDONLY);
 	if (fh != -1) {
-		if (ioctl(fh, CPUCTL_CPUID, &args) != 0) {
+		if (ioctl(fh, CPUCTL_CPUID_COUNT, &args) != 0) {
 			perror(cpuname);
 			exit(EXIT_FAILURE);
 		}
