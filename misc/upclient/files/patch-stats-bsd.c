--- src/stats-bsd.c.orig	Mon Dec 18 14:32:19 2000
+++ src/stats-bsd.c	Sat Dec 30 03:26:15 2000
@@ -12,57 +12,153 @@
 /* System includes */
 #include <stdio.h>
 #include <errno.h>
+#include <fcntl.h>
+#include <limits.h>
+#include <kvm.h>
 #include <syslog.h>
 #include <sys/time.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/dkstat.h>
+#include <devstat.h>
 #include <sys/utsname.h>
 
 /**
  * @desc	Get statistics
  */
 void getstats(unsigned long *puptime, double *pload, int *pidle, char *os, char *oslevel, char *cpu) {
-  struct utsname uts;
-  struct timeval boottime;
-  time_t now;
   size_t size;
-  double loadavgs[2];
-  int mib[2];
+  int mib [2];
+
+  {				/* ========== uptime ========== */
+    static struct timeval boottime;
+    static int initialized = 0;
+
+    if (!initialized) {
+      initialized = 1;
+
+      mib [0] = CTL_KERN;
+      mib [1] = KERN_BOOTTIME;
+
+      size = sizeof (boottime);
 
-  /* Get uptime */
-  time(&now);
-  mib[0] = CTL_KERN;
-  mib[1] = KERN_BOOTTIME;
-  size = sizeof(boottime);
-  if(sysctl(mib, 2, &boottime, &size, NULL, 0) != -1 && (boottime.tv_sec != 0)) {
-    *puptime = now - boottime.tv_sec;
-    *puptime /= 60;
-  }
-
-  if(cfg_sendload) {
-    /* Get load average */
-    getloadavg(loadavgs, 3);
-    /* Use the 3rd element (15 minute load average) */
-    *pload = loadavgs[2];
+      if (sysctl (mib, 2, &boottime, &size, NULL, 0) == -1)
+	err (1, "sysctl: kern.boottime");
   }
 
-  if(cfg_sendos) {
-    /* Get os info */
-    uname(&uts);
+    if (boottime.tv_sec) {
+      time_t now;
+
+      time (&now);
+
+      *puptime = (now - boottime.tv_sec) / 60;
+    }
+  }
+
+  if (cfg_sendidle) {		/* ========== idle_time ========== */
+    static kvm_t *kp;
+    static struct nlist namelist [] = {
+#define X_CP_TIME       0
+      { "_cp_time" },
+      { NULL },
+    };
+    static int initialized = 0;
+
+    if (!initialized) {
+      char errbuf [_POSIX2_LINE_MAX];
+      initialized = 1;
+
+      setgid (getgid ());
+
+      kp = kvm_openfiles (NULL, NULL, NULL, O_RDONLY, errbuf);
+
+      if (!kp)
+	warn ("kvm_openfiles: %s", errbuf);
+      else if (kvm_nlist (kp, namelist) == -1)
+	warn ("kvm_nlist: %s", kvm_geterr (kp));
+  }
+
+    if (kp) {
+      long ctime [CPUSTATES];
+      static long stime [CPUSTATES];
+      static int first_time = 1;
+
+      if (first_time) {
+	first_time = 0;
+
+	if (kvm_read (kp, namelist [X_CP_TIME].n_value,
+		      stime, sizeof (stime)) == -1)
+	  warn ("kvm_read: %s", kvm_geterr (kp));
+	else
+	  sleep (1);		/* to avoid the initial 0 idle value */
   }
 
-  if(cfg_sendcpu) {
-    /* Get CPU info */
-    mib[0] = CTL_HW;
-    mib[1] = HW_MODEL;
-    size = CPU_SIZE;
-    sysctl(mib, 2, cpu, &size, NULL, 0);
+      if (kvm_read(kp, namelist [X_CP_TIME].n_value,
+		   ctime, sizeof (ctime)) == -1)
+	warn ("kvm_read: %s", kvm_geterr (kp));
+      else {
+	int state;
+	double time = 0.;
+
+	for (state = 0; state < CPUSTATES; state++)
+	  time += ctime [state] - stime [state];
+
+	if (time == 0.)
+	  time = 1.;
+
+	*pidle = (ctime [CP_IDLE] - stime [CP_IDLE]) * 100. / time;
+
+	for (state = 0; state < CPUSTATES; state++)
+	  stime [state] = ctime [state];
+      }
+    } else
+      cfg_sendidle = 0;
+  }
+
+  if (cfg_sendload) {		/* ========== loadavg ========== */
+    double loadavgs [3] = { 0. };
+
+    getloadavg (loadavgs, 3);
+
+    *pload = loadavgs [2];
+  }
+
+  if (cfg_sendcpu) {		/* ========== cpu ========== */
+    static char buf [CPU_SIZE] = "";
+    static int initialized = 0;
+
+    if (!initialized) {
+      initialized = 1;
+
+      mib [0] = CTL_HW;
+      mib [1] = HW_MODEL;
+
+      size = sizeof (buf);
+
+      if (sysctl (mib, 2, buf, &size, NULL, 0) == -1)
+	warn ("sysctl: hw.model");
+    }
+
+    strncpy (cpu, buf, CPU_SIZE);
+    cpu [CPU_SIZE - 1] = 0;
   }
 
   if(cfg_sendos) {
-    strncpy(os, uts.sysname, OS_SIZE - 1);
-    if(cfg_sendoslevel) {
-      strncpy(oslevel, uts.release, OSLEVEL_SIZE - 1);
+    static struct utsname uts;
+    static int initialized = 0;
+
+    if (!initialized) {
+      initialized = 1;
+
+      uname(&uts);
+    }
+
+    strncpy (os, uts.sysname, OS_SIZE - 1);
+    os [OS_SIZE - 1] = 0;
+
+    if (cfg_sendoslevel) {
+      strncpy (oslevel, uts.release, OSLEVEL_SIZE - 1);
+      oslevel [OSLEVEL_SIZE - 1] = 0;
     }
   }
 }
