--- freebsd.c.orig	Wed Dec 22 20:52:33 2004
+++ freebsd.c	Wed Dec 22 21:34:40 2004
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
@@ -19,11 +17,48 @@
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/if_mib.h>
+#include <sys/socket.h>
 #include <ifaddrs.h>
 
 #define GETSYSCTL(name, var) getsysctl(name, &(var), sizeof(var))
 #define KELVTOC(x)      ((x - 2732) / 10.0)
 
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
+
+
 static int getsysctl(char *name, void *ptr, size_t len)
 {   
 	size_t nlen = len;
@@ -344,4 +379,34 @@
 
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
 }
