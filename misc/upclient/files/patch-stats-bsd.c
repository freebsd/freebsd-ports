--- src/stats-bsd.c.orig	Sat Nov 30 03:27:16 2002
+++ src/stats-bsd.c	Wed Dec 18 03:28:16 2002
@@ -64,6 +64,8 @@
 
 #include "locale.h"     /* gettext */
 
+void logcalc(char *, char *);
+
 /**
  * @desc    Verbose level 2 logging of calulations
  */
@@ -81,12 +83,13 @@
 void
 initCPU(char *cpu)
 {
-    char   buf[CPU_SIZE] = "";
     static int initialized = 0;
-    size_t size;
-    int    mib[2];
 
     if (!initialized) {
+	char   buf[CPU_SIZE] = "";
+	size_t size;
+	int    mib[2];
+
         initialized = 1;
 
         mib[0] = CTL_HW;
@@ -98,7 +101,6 @@
 
         if (sysctl(mib, 2, buf, &size, NULL, 0) == -1) {
             uplog(LOG_WARNING, "sysctl: hw.model");
-           /* warn("sysctl: hw.model"); */
         }
         strlcpy(cpu, buf, CPU_SIZE);
         logcalc(_("CPU"), cpu);
@@ -154,7 +156,6 @@
             err(1, "sysctl: kern.boottime");
         }
         boottimesecs = boottime.tv_sec;
-       /* logcalc(_("boot time"), boottimesecs); */
 #if defined DEBUG
         uplog(LOG_DEBUG, "initBoottime() initialized %d", boottimesecs);
 #endif /* DEBUG */
@@ -173,19 +174,18 @@
               _("%s %s not implemented for this operating system %s"),
               _("WARNING:"), _("Load-average"), strerror(errno));
         cfg_SendUsage = 0;
-        return;
     }
     else if (loads < 0) {
         uplog(LOG_WARNING, _("%s Could not get load-average %s"), _("WARNING:"),
               strerror(errno));
-        return;
     }
-
-   /* Use the 3rd element (15 minute Load-average) */
-    *loadavg = loadavgs[2];
+    else {
+	/* Use the 3rd element (15 minute Load-average) */
+	*loadavg = loadavgs[2];
 #if defined DEBUG
-    uplog(LOG_DEBUG, "getLoadavg() %.2f", *loadavg);
+	uplog(LOG_DEBUG, "getLoadavg() %.2f", *loadavg);
 #endif /* DEBUG */
+    }
 }
 
 #if !defined __MACH__   /* Mach kernel stuff is in stats-mach.c */
@@ -245,7 +245,7 @@
 
             for (state = 0; state < CPUSTATES; state++) {
                 time += ctime[state] - stime[state];
-                if (!(state == CPU_STATE_IDLE)) {
+                if (!(state == CP_IDLE)) {
                     nonidlecpu += (float)(ctime[state] - stime[state]);
                 }
             }
@@ -258,6 +258,10 @@
 
             for (state = 0; state < CPUSTATES; state++)
                 stime[state] = ctime[state];
+#if defined DEBUG
+	    uplog(LOG_DEBUG, "getLoadIdle() load=%.1f idle=%.1f", *UsagePercent,
+		  *IdlePercent);
+#endif /* DEBUG */
         }
     }
     else {
@@ -268,17 +272,13 @@
         cfg_SendUsage = 0;
         cfg_SendIdle = 0;
     }
-#if defined DEBUG
-    uplog(LOG_DEBUG, "getLoadIdle() load=%.1f idle=%.1f", *UsagePercent,
-          *IdlePercent);
-#endif /* DEBUG */
 }
 #endif /* !__MACH__ */
 
 void
 getUptime(unsigned long *uptimeminutes)
 {
-    static time_t boottimesecs;
+    time_t boottimesecs;
 
     boottimesecs = initBoottime();
 
@@ -293,7 +293,7 @@
 #endif /* DEBUG */
     }
     else {
-        uplog(LOG_INFO, _("%s: %s failed"), _("ERROR:"),
+        uplog(LOG_ERR, _("%s %s failed"), _("ERROR:"),
               "getUptime() boottime.tv_sec");
     }
 }
@@ -306,19 +306,18 @@
          double *IdlePercent, char *osname, char *osversion, char *cpu,
          double *loadavg)
 {
-    getUptime(&*uptimeminutes);
+    getUptime(uptimeminutes);
 
     if (cfg_SendUsage || cfg_SendIdle)
-        getLoadIdle(&*UsagePercent, &*IdlePercent);
+        getLoadIdle(UsagePercent, IdlePercent);
 
     if (cfg_sendosname || cfg_sendosversion)
-        initOS(&*osname, &*osversion);
+        initOS(osname, osversion);
 
     if (cfg_sendcpu)
-        initCPU(&*cpu);
-
-   /* if (cfg_sendloadavg) */
-    getLoadavg(&*loadavg);
+        initCPU(cpu);
 
+    if (cfg_sendloadavg)
+	getLoadavg(loadavg);
 }
 #endif /* PLATFORM_BSD */
