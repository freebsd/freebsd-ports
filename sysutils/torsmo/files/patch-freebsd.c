--- freebsd.c.dist	Wed Jul 13 09:34:20 2005
+++ freebsd.c	Wed Jul 13 09:34:26 2005
@@ -4,14 +4,12 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <time.h>
-#include <sys/time.h>
 #include <kvm.h>
 #include <sys/param.h>
-#include <sys/resource.h>
-#include <sys/sysctl.h>
 #include <sys/types.h>
 #include <sys/time.h>
+#include <sys/resource.h>
+#include <sys/sysctl.h>
 #include <sys/vmmeter.h>
 #include <sys/dkstat.h>
 #include <unistd.h>
@@ -19,11 +17,50 @@
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_mib.h>
+#include <sys/socket.h>
 #include <ifaddrs.h>
 
 #define GETSYSCTL(name, var) getsysctl(name, &(var), sizeof(var))
 #define KELVTOC(x)      ((x - 2732) / 10.0)
 
+#if defined(i386) || defined(__i386__)
+static unsigned int get_timer();
+static unsigned int get_cpu_speed(void);
+static inline unsigned long long int rdtsc( void );
+
+/* cpu frequency detection code based on mplayer's one */
+
+static unsigned int get_timer() {
+	struct timeval tv;
+	struct timezone tz;
+	gettimeofday(&tv,&tz);
+       
+	return (tv.tv_sec*1000000+tv.tv_usec);
+}
+
+static inline unsigned long long int rdtsc( void )
+{
+	unsigned long long int retval;
+	__asm __volatile ("rdtsc":"=A"(retval)::"memory");
+	return retval;
+}
+				    
+static unsigned int get_cpu_speed(void)
+{
+	unsigned long long int tscstart, tscstop;
+	unsigned int start, stop;
+    
+	tscstart = rdtsc();
+	start = get_timer();
+	usleep(50000);
+	stop = get_timer();
+	tscstop = rdtsc();
+
+    	return((tscstop-tscstart)/((stop-start)/1000.0));
+} 
+#endif
+
+
 static int getsysctl(char *name, void *ptr, size_t len)
 {   
 	size_t nlen = len;
@@ -91,7 +128,7 @@
 	int mib[2] = {CTL_KERN, KERN_BOOTTIME};
       	struct timeval boottime;
         time_t now;
-	int size = sizeof(boottime);
+	size_t size = sizeof(boottime);
 
 	if((sysctl(mib, 2, &boottime, &size, NULL, 0) != -1) && (boottime.tv_sec != 0)) {
 		time(&now);
@@ -292,7 +329,7 @@
 }
 
 double get_acpi_temperature(int fd) {
-	double temp;
+	int temp;
        
 	if (GETSYSCTL("hw.acpi.thermal.tz0.temperature", temp)) {
         	(void)fprintf(stderr, "Cannot read sysctl \"hw.acpi.thermal.tz0.temperature\"\n");
@@ -303,15 +340,19 @@
 }
 
 void get_battery_stuff(char *buf, unsigned int n, const char *bat) {
-	int battime;
+	int battime, batlife, state;
              
 	if (GETSYSCTL("hw.acpi.battery.time", battime))
 		(void)fprintf(stderr, "Cannot read sysctl \"hw.acpi.battery.time\"\n");
+	if (GETSYSCTL("hw.acpi.battery.life", batlife))
+		(void)fprintf(stderr, "Cannot read sysctl \"hw.acpi.battery.life\"\n");
+	if (GETSYSCTL("hw.acpi.acline", state))
+		(void)fprintf(stderr, "Cannot read sysctl \"hw.acpi.acline\"\n");
                      
 	if (battime != -1)
-        	snprintf(buf, n, "Discharging, remaining %d:%2.2d", battime / 60, battime % 60);
+        	snprintf(buf, n, "%d:%2.2d%s", battime / 60, battime % 60, (state? " (charging)":""));
 	else
-        	snprintf(buf, n, "Battery is charging");
+		snprintf(buf, n, "%d%%%s", batlife, (state? " (charging)":""));
 }
 
 int open_i2c_sensor(const char *dev, const char *type, int n, int *div)
@@ -344,4 +385,38 @@
 
 char* get_acpi_fan() {
 	return "";
+}
+
+char* get_adt746x_cpu() {
+	return "";
+}
+
+char* get_adt746x_fan() {
+	return "";
+}
+
+char* get_freq() {
+#if defined(i386) || defined(__i386__)
+	int i;
+	char *cpuspeed;
+
+	if ((cpuspeed = (char *)malloc(16)) == NULL)
+		exit(1);
+	
+	i = 0;
+	if ((i = get_cpu_speed()) > 0) {
+        	if (i < 1000000) {
+			i += 50; /* for rounding */
+			snprintf(cpuspeed, 15, "%d.%d MHz", i/1000, (i/100)%10);
+		} else {
+			snprintf(cpuspeed, 15, "%d MHz", i/1000);
+		}
+	} else {
+		cpuspeed = "";
+	}
+
+	return cpuspeed;
+#else
+	return "";
+#endif
 }
