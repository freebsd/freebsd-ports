--- wmzazof.c	Mon Dec 17 13:55:01 2001
+++ wmzazof-patch.c	Tue Dec 18 12:04:23 2001
@@ -24,6 +24,11 @@
 #include <dockapp.h>
 #include <unistd.h>
 #include <string.h>
+#include <time.h>
+#include <sys/time.h>
+#include <sys/sysctl.h>
+#include <sys/vmmeter.h>
+#include <vm/vm_param.h>
 #include "pix/master.xpm"
 #include "pix/numbers.xpm"
 #include "pix/char.xpm"
@@ -61,6 +66,9 @@
 
 char *displayName = "";
 
+struct timeval boottime;
+int page_size;
+
 unsigned int *cmdline;
 
 FILE *file;
@@ -130,43 +138,22 @@
 
 void check_values()
 {
-	char input[128];
-	char* token = " ";
-	char* uptime_s;
-	char* mem_used_s;
-	char* mem_free_s;
-	char* mem_cached_s;
-	char* temp_s;
+	time_t now = time(NULL);
+	int mib[2] = { CTL_VM, VM_METER }, mcs = sizeof(mem_cached);
+	struct vmtotal meter;
+	size_t size = sizeof(meter);
 	
-	/* /proc/uptime
-	 *
-	 * first value is the uptime in seconds
-	 */
-	file = fopen("/proc/uptime", "r");
-	fgets(input, 128, file);
-	fclose(file);
-	uptime_s = strtok(input, token);
 	// uptime in seconds
-	uptime = atoi(uptime_s);
-	
-	/* /proc/meminfo
-	 * 
-	 */
-	file = fopen("/proc/meminfo", "r");
-	fgets(input, 128, file);
-	fgets(input, 128, file);
-	fclose(file);
-	temp_s = strtok(input, token);
-	temp_s = strtok(NULL, token); // total
-	mem_used_s = strtok(NULL, token); // used
-	mem_free_s = strtok(NULL, token); // free
-	temp_s = strtok(NULL, token); // shared
-	temp_s = strtok(NULL, token); // buffers
-	mem_cached_s = strtok(NULL, token); // cached
+	uptime = now - boottime.tv_sec;
+
 	// in Kb
-	mem_used = atoi(mem_used_s) / 1024;
-	mem_free = atoi(mem_free_s) / 1024;
-	mem_cached = atoi(mem_cached_s) / 1024;
+	if (sysctl(mib, 2, &meter, &size, NULL, 0) != -1 &&
+	sysctlbyname("vm.stats.vm.v_cache_count", &mem_cached, &mcs, NULL, 0) != -1)
+	{
+		mem_used = meter.t_rm * page_size / 1024;
+		mem_free = meter.t_free * page_size / 1024;
+		mem_cached = mem_cached * page_size / 1024;
+	}
 }
 
 void transform_values()
@@ -219,6 +206,9 @@
 int main (int argc, char **argv)
 {
 	unsigned int height, width;
+
+	int mib[2] = { CTL_KERN, KERN_BOOTTIME };
+	size_t size_bt = sizeof(boottime), size_ps = sizeof(page_size);
 	
 	DACallbacks callbacks = { NULL, buttonPressCallback, NULL, NULL, NULL, NULL, NULL }; 
 
@@ -238,6 +228,12 @@
 	state_mem_free = MEM_FREE_CACHED;
 	state_mem_used = MEM_USED_CACHED;
 
+	if (sysctl(mib, 2, &boottime, &size_bt, NULL, 0) == -1 ||
+   sysctlbyname("vm.stats.vm.v_page_size", &page_size, &size_ps, NULL, 0) == -1)
+	{
+		perror(NULL);
+		exit(EXIT_FAILURE);
+	}
 	
 	while (1)
 	{
