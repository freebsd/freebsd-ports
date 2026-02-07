--- src/stats-bsd.c.orig	Tue May 27 09:03:43 2003
+++ src/stats-bsd.c	Wed Jun 11 23:48:40 2003
@@ -73,6 +73,8 @@
 
 #include "locale.h"     /* gettext */
 
+void logcalc(char *, char *);
+
 /**
  * @desc    Verbose level 3 logging of calulations
  */
@@ -90,12 +92,13 @@
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
@@ -180,19 +183,18 @@
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
@@ -266,6 +268,10 @@
            /* store values for next calculation interval */
             for (state = 0; state < CPUSTATES; state++)
                 stime[state] = ctime[state];
+#if defined DEBUG
+	    uplog(LOG_DEBUG, "getLoadIdle() load=%.1f idle=%.1f", *UsagePercent,
+		  *IdlePercent);
+#endif /* DEBUG */
         }
     }
     else {
@@ -276,17 +282,13 @@
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
 
@@ -301,7 +303,7 @@
 #endif /* DEBUG */
     }
     else {
-        uplog(LOG_INFO, _("%s: %s failed"), _("ERROR:"),
+        uplog(LOG_ERR, _("%s %s failed"), _("ERROR:"),
               "getUptime() boottime.tv_sec");
     }
 }
@@ -314,21 +316,20 @@
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
+        initCPU(cpu);
 
    /* WARNING: loadavg is not implemented on Wonko server! */
    /* cfg_SendUsage is implemented instead. (i.e. only CPU usage % a la `top`) */
-   /* if (cfg_sendloadavg) */
-    getLoadavg(&*loadavg);
-
+   if (cfg_sendloadavg)
+	getLoadavg(loadavg);
 }
 #endif /* PLATFORM_BSD */
