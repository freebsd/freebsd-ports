--- src/stats-bsd.c.orig	Sat Jun 16 21:12:53 2001
+++ src/stats-bsd.c	Sun Nov 18 17:33:52 2001
@@ -26,37 +26,50 @@
  * @desc	Get statistics
  */
 void getstats(unsigned long *puptime, double *pload, int *pidle, char *os, char *oslevel, char *cpu) {
-  struct utsname uts;
-  struct timeval boottime;
-  time_t now;
   size_t size;
-  double loadavgs[2];
   int mib[2];
 
-  /* Get uptime */
-  time(&now);
+  {					/* ========== uptime ========== */
+    static struct timeval boottime;
+    static int initialized = 0;
+    time_t now;
+
+    if (!initialized) {
+      initialized = 1;
+
   mib[0] = CTL_KERN;
   mib[1] = KERN_BOOTTIME;
   size = sizeof(boottime);
-  if(sysctl(mib, 2, &boottime, &size, NULL, 0) != -1 && (boottime.tv_sec != 0)) {
+
+      if (sysctl (mib, 2, &boottime, &size, NULL, 0) == -1)
+	err (1, "sysctl: kern.boottime");
+    }
+
+    if (boottime.tv_sec) {
+      time_t now;
+
+      time (&now);
+
     *puptime = now - boottime.tv_sec;
     *puptime /= 60;
   }
+  }
+
+  if(cfg_sendload) {			/* ========== loadavg ========== */
+    double loadavgs[3] = { 0. };
 
-  if(cfg_sendload) {
-    /* Get load average */
     getloadavg(loadavgs, 3);
     /* Use the 3rd element (15 minute load average) */
     *pload = loadavgs[2];
   }
 
-  if(cfg_sendos) {
-    /* Get os info */
-    uname(&uts);
-  }
+  if(cfg_sendcpu) {			/* ========== cpu ========== */
+    static char buf [CPU_SIZE] = "";
+    static int initialized = 0;
+
+    if (!initialized) {
+      initialized = 1;
 
-  if(cfg_sendcpu) {
-    /* Get CPU info */
     mib[0] = CTL_HW;
     if(cfg_sendcpulevel == 1) {
       mib[1] = HW_MACHINE; /* Send architecture */
@@ -64,17 +77,35 @@
       mib[1] = HW_MODEL;   /* Send architecture's specific model */
     }
     size = CPU_SIZE;
-    sysctl(mib, 2, cpu, &size, NULL, 0);
+
+      if (sysctl (mib, 2, buf, &size, NULL, 0) == -1)
+	warn ("sysctl: hw.model");
+    }
+
+    strncpy (cpu, buf, CPU_SIZE);
+    cpu [CPU_SIZE - 1] = 0;
   }
 
   if(cfg_sendos) {
+    static struct utsname uts;
+    static int initialized = 0;
+
+    if (!initialized) {
+      initialized = 1;
+	    
+      uname(&uts);
+    }
+
     strncpy(os, uts.sysname, OS_SIZE - 1);
+    os [OS_SIZE - 1] = 0;
+
     if(cfg_sendoslevel) {
       strncpy(oslevel, uts.release, OSLEVEL_SIZE - 1);
+      oslevel [OSLEVEL_SIZE - 1] = 0;
     }
   }
 
-  if(cfg_sendidle) {
+  if(cfg_sendidle) {			/* ========== idle_time ========== */
     static kvm_t *kp;
     static int initialized = 0;
     static struct nlist namelist [] = {
