
$FreeBSD$

--- srclib/libmetrics/freebsd/metrics.c.orig
+++ srclib/libmetrics/freebsd/metrics.c
@@ -6,7 +6,7 @@
  *  Fixed libkvm code.
  *  Tue Jul 15 16:42:22 EST 2003
  *
- * $Id: metrics.c,v 1.4 2005/01/29 01:24:01 brooks_en_davis Exp $
+ * $Id: metrics.c,v 1.5 2005/03/04 21:22:32 brooks_en_davis Exp $
  */
 #include <stdio.h>
 #include <stdlib.h>
@@ -47,10 +47,16 @@
 #define MIN_NET_POLL_INTERVAL 0.5
 #endif
 
+#ifndef MIN_CPU_POLL_INTERVAL
+#define MIN_CPU_POLL_INTERVAL 0.5
+#endif
+
 #ifndef UINT64_MAX
 #define UINT64_MAX	ULLONG_MAX
 #endif
 
+#define VFCF_NONLOCAL	(VFCF_NETWORK|VFCF_SYNTHETIC|VFCF_LOOPBACK)
+
 #define timertod(tvp) \
     ((double)(tvp)->tv_sec + (double)(tvp)->tv_usec/(1000*1000))
 
@@ -111,23 +117,18 @@
       kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "metric_init()");
    } else {
       /*
-       * Versions of FreeBSD with the swap mib generally have a version
+       * RELEASE versions of FreeBSD with the swap mib have a version
        * of libkvm that doesn't need root for simple proc access so we
-       * just open /dev/null to give us a working handle here.  This is
-       * bogus, but only a few pre-release versions of 5.0 are
-       * affected by the bogosity and people running those should
-       * upgrade.
+       * just open /dev/null to give us a working handle here.
        */
       kd = kvm_open(_PATH_DEVNULL, NULL, NULL, O_RDONLY, "metric_init()");
       use_vm_swap_info = 1;
    }
    pagesize = getpagesize();
 
-   /*
-    * Call get_netbw once to initalize the counters.
-    */
-
+   /* Initalize some counters */
    get_netbw(NULL, NULL, NULL, NULL);
+   cpu_state(-1);
 
    val.int32 = SYNAPSE_SUCCESS;
    return val;
@@ -152,12 +153,15 @@
    g_val_t val;
    int cpu_speed;
    size_t len = sizeof(cpu_speed);
-   if (sysctlbyname("machdep.tsc_freq", &cpu_speed, &len, NULL, 0) == -1)
-     val.uint16 = 0;
 
-   /* machdep.tsc_freq doesn't seem to always be present. At least on
-      my FreeBSD 4 systems. The experts say it gives cpu speed, tho. */
+   /*
+    * machdep.tsc_freq is an i386/amd64 only feature, but it's the best
+    * we've got at the moment.
+    */
+   if (sysctlbyname("machdep.tsc_freq", &cpu_speed, &len, NULL, 0) == -1)
+     cpu_speed = 0;
    val.uint16 = cpu_speed /= 1000000;
+
    return val;
 }
 
@@ -166,16 +170,14 @@
 {
    g_val_t val;
    size_t len;
-   int total;
-   int mib[2];
+   long total;
 
-   mib[0] = CTL_HW;
-   mib[1] = HW_PHYSMEM;
-   len = sizeof (total);
+   len = sizeof(total);
+
+   if (sysctlbyname("hw.physmem", &total, &len, NULL, 0) == -1)
+	total = 0;
+   val.uint32 = total / 1024;
 
-   sysctl(mib, 2, &total, &len, NULL, 0);
-   total /= 1024;
-   val.uint32 = total;
    return val;
 }
 
@@ -216,17 +218,14 @@
 boottime_func ( void )
 {
    g_val_t val;
-   struct timeval  boottime;
-   int mib[2];
+   struct timeval boottime;
    size_t size;
 
-   mib[0] = CTL_KERN;
-   mib[1] = KERN_BOOTTIME;
    size = sizeof(boottime);
-   if (sysctl(mib, 2, &boottime, &size, NULL, 0) == -1)
-       val.uint32 = 0;
+   if (sysctlbyname("kern.boottime", &boottime, &size, NULL, 0) == -1)
+       boottime.tv_sec = 0;
 
-   val.uint32 = boottime.tv_sec;
+   val.uint32 = (uint32_t) boottime.tv_sec;
 
    return val;
 }
@@ -243,49 +242,40 @@
 g_val_t
 machine_type_func ( void )
 {
-   g_val_t val;
-   char machine_type[MAX_G_STRING_SIZE];
-   size_t len = MAX_G_STRING_SIZE;
-   if (sysctlbyname("hw.machine", &machine_type, &len, NULL, 0) == -1 || !len)
-        strncpy( val.str, "x86", MAX_G_STRING_SIZE );
+	g_val_t val;
+	size_t len = sizeof(val.str);
 
-   strncpy( val.str, machine_type, MAX_G_STRING_SIZE );
-   return val;
+	if (sysctlbyname("hw.machine", val.str, &len, NULL, 0) == -1 ||
+	    (len == 0))
+		strlcpy(val.str, "unknown", sizeof(val.str));
+
+	return val;
 }
 
 g_val_t
 os_name_func ( void )
 {
-   g_val_t val;
-   char osname[MAX_G_STRING_SIZE];
-   size_t len = MAX_G_STRING_SIZE;
-   if (sysctlbyname("kern.ostype", &osname, &len, NULL, 0) == -1 || !len)
-        strncpy( val.str, "FreeBSD", MAX_G_STRING_SIZE );
+	g_val_t val;
+	size_t len = sizeof(val.str);
 
-   strncpy( val.str, osname, MAX_G_STRING_SIZE );
- 
-   return val;
+	if (sysctlbyname("kern.ostype", val.str, &len, NULL, 0) == -1 ||
+	    (len == 0))
+		strlcpy(val.str, "FreeBSD (unknown)", sizeof(val.str));
+
+	return val;
 }        
 
 g_val_t
 os_release_func ( void )
 {
-   g_val_t val;
-   int mib[2];
-   size_t len;
-   char *prefix, buf[1024];
-
-   prefix = "";
-
-   mib[0] = CTL_KERN;
-   mib[1] = KERN_OSRELEASE;
-   len = sizeof(buf);
-   if (sysctl(mib, 2, &buf, &len, NULL, 0) == -1)
-        strncpy( val.str, "Unknown", MAX_G_STRING_SIZE );
+	g_val_t val;
+	size_t len = sizeof(val.str);
 
-   strncpy( val.str, buf, MAX_G_STRING_SIZE );
+	if (sysctlbyname("kern.osrelease", val.str, &len, NULL, 0) == -1 ||
+	    (len == 0))
+		strlcpy(val.str, "unknown", sizeof(val.str));
 
-   return val;
+	return val;
 }        
 
 /* Get the CPU state given by index, from kern.cp_time
@@ -294,21 +284,37 @@
  */
 int cpu_state(int which) {
 
-   static long cp_time[CPUSTATES];
+   long cp_time[CPUSTATES];
+   long cp_diff[CPUSTATES];
    static long cp_old[CPUSTATES];
-   static long cp_diff[CPUSTATES];
    static int cpu_states[CPUSTATES];
-   static long tot;
+   static struct timeval this_time, last_time;
+   struct timeval time_diff;
    size_t len = sizeof(cp_time);
+   int i;
+
+   if (which == -1) {
+      bzero(cp_old, sizeof(cp_old));
+      bzero(&last_time, sizeof(last_time));
+      return 0.0;
+   }
+
+   gettimeofday(&this_time, NULL);
+   timersub(&this_time, &last_time, &time_diff);
+   if (timertod(&time_diff) < MIN_CPU_POLL_INTERVAL) {
+      goto output;
+   }
+   last_time = this_time;
 
-   /* Copy the last cp_time into cp_old */
-   memcpy(&cp_old, &cp_time, CPUSTATES*sizeof(long));
    /* puts kern.cp_time array into cp_time */
-   if (sysctlbyname("kern.cp_time", &cp_time, &len, NULL, 0) == -1 || !len)
+   if (sysctlbyname("kern.cp_time", &cp_time, &len, NULL, 0) == -1) {
+      warn("kern.cp_time");
       return 0.0;
+   }
    /* Use percentages function lifted from top(1) to figure percentages */
-   tot = percentages(CPUSTATES, cpu_states, cp_time, cp_old, cp_diff);
+   percentages(CPUSTATES, cpu_states, cp_time, cp_old, cp_diff);
 
+output:
    return cpu_states[which];
 }
 
@@ -316,10 +322,9 @@
 cpu_user_func ( void )
 {
    g_val_t val;
-   int res;
 
-   res = cpu_state(CP_USER); 
-   val.f = (float)res/10;
+   val.f = (float) cpu_state(CP_USER)/10;
+
    return val;
 }
 
@@ -327,10 +332,8 @@
 cpu_nice_func ( void )
 {
    g_val_t val;
-   int res;
 
-   res = cpu_state(CP_NICE); 
-   val.f = (float)res/10;
+   val.f = (float) cpu_state(CP_NICE)/10;
 
    return val;
 }
@@ -339,10 +342,8 @@
 cpu_system_func ( void )
 {
    g_val_t val;
-   int res;
 
-   res = cpu_state(CP_SYS); 
-   val.f = (float)res/10;
+   val.f = (float) cpu_state(CP_SYS)/10;
 
    return val;
 }
@@ -351,16 +352,14 @@
 cpu_idle_func ( void )
 {
    g_val_t val;
-   int res;
 
-   res = cpu_state(CP_IDLE); 
-   val.f = (float)res/10;
+   val.f = (float) cpu_state(CP_IDLE)/10;
 
    return val;
 }
 
 /*
-** FIXME
+** FIXME - This metric is not valid on FreeBSD.
 */
 g_val_t 
 cpu_wio_func ( void )
@@ -372,7 +371,8 @@
 }
 
 /*
-** FIXME
+** FIXME - Idle time since startup.  The scheduler apparently knows
+** this, but we it's fairly pointless so it's not exported.
 */
 g_val_t 
 cpu_aidle_func ( void )
@@ -382,19 +382,18 @@
    return val;
 }
 
-/*
-** FIXME
-*/
 g_val_t 
 cpu_intr_func ( void )
 {
    g_val_t val;
-   val.f = 0.0;
+
+   val.f = (float) cpu_state(CP_INTR)/10;
+
    return val;
 }
 
 /*
-** FIXME
+** FIXME - This metric is not valid on FreeBSD.
 */
 g_val_t 
 cpu_sintr_func ( void )
@@ -412,6 +411,7 @@
 
    getloadavg(load, 3);
    val.f = load[0];
+
    return val;
 }
 
@@ -422,8 +422,8 @@
    double load[3];
 
    getloadavg(load, 3);
- 
    val.f = load[1];
+
    return val;
 }
 
@@ -435,6 +435,7 @@
 
    getloadavg(load, 3);
    val.f = load[2];
+
    return val;
 }
 
@@ -442,14 +443,9 @@
 proc_total_func ( void )
 {
    g_val_t val;
-   int mib[3];
-   size_t len;
-
-   mib[0] = CTL_KERN;
-   mib[1] = KERN_PROC;
-   mib[2] = KERN_PROC_ALL;
+   size_t len = 0;
 
-   sysctl(mib, 3, NULL, &len, NULL, 0);
+   sysctlbyname("kern.proc.all", NULL, &len, NULL, 0);
 
    val.uint32 = (len / sizeof (struct kinfo_proc)); 
 
@@ -457,9 +453,6 @@
 }
 
 
-/* 
- * Don't know how to do this yet..
- */
 g_val_t
 proc_run_func( void )
 {
@@ -501,6 +494,12 @@
    return val;
 }
 
+/*
+** FIXME - The whole ganglia model of memory is bogus.  Free memory is
+** generally a bad idea with a modern VM and so is reporting it.  There
+** is simply no way to report a value for "free" memory that makes any
+** kind of sense.  Free+inactive might be a decent value for "free".
+*/
 g_val_t
 mem_free_func ( void )
 {
@@ -516,15 +515,25 @@
    return val;
 }
 
+/*
+** FreeBSD don't seem to report this anywhere.  It's actually quite
+** complicated as there is SysV shared memory, POSIX shared memory,
+** and mmap shared memory at a minimum.
+*/
 g_val_t
 mem_shared_func ( void )
 {
    g_val_t val;
 
    val.uint32 = 0;
+
    return val;
 }
 
+/*
+** FIXME - this isn't really valid.  It lists some VFS buffer space,
+** but the real picture is much more complex.
+*/
 g_val_t
 mem_buffers_func ( void )
 {
@@ -541,6 +550,10 @@
    return val;
 }
 
+/*
+** FIXME - this isn't really valid.  It lists some VM cache space,
+** but the real picture is more complex.
+*/
 g_val_t
 mem_cached_func ( void )
 {
@@ -790,8 +803,6 @@
  * at ftp://ftp.cs.berkeley.edu/pub/4bsd/README.Impt.License.Change.
  */
 
-
-
 static float
 find_disk_space(double *total, double *tot_avail)
 {
@@ -911,6 +922,7 @@
 makenetvfslist(void)
 {
 	char *str = NULL, *strptr, **listptr = NULL;
+	size_t slen;
 	int cnt, i;
 
 #if __FreeBSD_version > 500000
@@ -938,15 +950,16 @@
 		goto done;
 	}
 
-	for (cnt = 0, i = 0; i < maxvfsconf; i++) {
-		if (xvfsp->vfc_flags & (VFCF_NETWORK|VFCF_SYNTHETIC|VFCF_LOOPBACK)) {
-			listptr[cnt++] = strdup(xvfsp->vfc_name);
-			if (listptr[cnt-1] == NULL) {
-				warnx("malloc failed");
-				goto done;
-			}
+	for (cnt = 0; cnt < maxvfsconf; xvfsp++) {
+		if (xvfsp->vfc_flags & VFCF_NONLOCAL)
+			continue;
+
+		listptr[cnt] = strdup(xvfsp->vfc_name);
+		if (listptr[cnt] == NULL) {
+			warnx("malloc failed");
+			goto done;
 		}
-		xvfsp++;
+		cnt++;
 	}
 #else
 	int mib[3], maxvfsconf;
@@ -966,31 +979,45 @@
 		goto done;
 	}
 
-	for (ptr = getvfsent(); ptr; ptr = getvfsent())
-		if (ptr->vfc_flags & (VFCF_NETWORK|VFCF_SYNTHETIC|VFCF_LOOPBACK)) {
-			listptr[cnt++] = strdup(ptr->vfc_name);
-			if (listptr[cnt-1] == NULL) {
-				warnx("malloc failed");
-				goto done;
-			}
+	cnt = 0;
+	while ((ptr = getvfsent()) != NULL && cnt < maxvfsconf) {
+		if (ptr->vfc_flags & VFCF_NONLOCAL)
+			continue;
+
+		listptr[cnt] = strdup(ptr->vfc_name);
+		if (listptr[cnt] == NULL) {
+			warnx("malloc failed");
+			goto done;
 		}
+		cnt++;
+	}
 #endif
 
 	if (cnt == 0)
 		goto done;
 
-	if ((str = malloc(sizeof(char) * (32 * cnt + cnt + 2))) == NULL) {
+	/*
+	 * Count up the string lengths, we need a extra byte to hold
+	 * the between entries ',' or the NUL at the end.
+	 */
+	for (i = 0; i < cnt; i++)
+		slen = strlen(listptr[i]) + 1;
+	/* Add 2 for initial "no". */
+	slen += 2;
+
+	if ((str = malloc(slen)) == NULL) {
 		warnx("malloc failed");
 		goto done;
 	}
 
-	*str = 'n'; *(str + 1) = 'o';
+	str[0] = 'n';
+	str[1] = 'o';
 	for (i = 0, strptr = str + 2; i < cnt; i++, strptr++) {
-		strncpy(strptr, listptr[i], 32);
+		strcpy(strptr, listptr[i]);
 		strptr += strlen(listptr[i]);
 		*strptr = ',';
 	}
-	*(--strptr) = '\0';
+	*strptr = '\0';
 
 done:
 #if __FreeBSD_version > 500000
@@ -1044,7 +1071,6 @@
 	if (timertod(&time_diff) < MIN_NET_POLL_INTERVAL) {
 		goto output;
 	}
-
 
 	if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
 		errx(1, "iflist-sysctl-estimate");
