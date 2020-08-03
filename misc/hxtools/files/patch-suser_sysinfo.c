--- suser/sysinfo.c.orig	2020-07-12 09:44:16 UTC
+++ suser/sysinfo.c
@@ -48,9 +48,9 @@ struct sy_block {
 	unsigned int display_width, display_height;
 };
 
-static const char *sy_osrelease_file = "/etc/os-release";
-static const char *sy_cpuinfo_file = "/proc/cpuinfo";
-static const char sysfs_cpu_dir[] = "/sys/devices/system/cpu";
+static const char *sy_osrelease_file = "/var/run/os-release";
+static const char *sy_cpuinfo_file = "/compat/linux/proc/cpuinfo";
+static const char sysfs_cpu_dir[] = "/compat/linux/sys/devices/system/cpu";
 static unsigned int sy_verbose;
 
 static void sy_num_cpu_threads(struct sy_block *sib)
@@ -190,7 +190,7 @@ static void sy_loadavg(struct sy_block *sib)
 {
 	double avg5, avg15;
 	unsigned int run;
-	FILE *fp = fopen("/proc/loadavg", "r");
+	FILE *fp = fopen("/compat/linux/proc/loadavg", "r");
 
 	if (fp == NULL)
 		return;
@@ -202,7 +202,7 @@ static void sy_loadavg(struct sy_block *sib)
 static void sy_memory(struct sy_block *sib)
 {
 	unsigned long long mem_free = 0, mem_buf = 0, mem_cac = 0, mem_shm = 0;
-	FILE *fp = fopen("/proc/meminfo", "r");
+	FILE *fp = fopen("/compat/linux/proc/meminfo", "r");
 	hxmc_t *line = NULL;
 	char *key, *value;
 
@@ -448,6 +448,7 @@ int main(int argc, const char **argv)
 	sy_gfx_hardware(&sib);
 	sy_display_size(&sib);
 	sy_dump(&sib);
-	HXmap_free(sib.osrel);
+	if (sib.osrel)
+		HXmap_free(sib.osrel);
 	return EXIT_SUCCESS;
 }
