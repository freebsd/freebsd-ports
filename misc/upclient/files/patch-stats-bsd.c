--- src/stats-bsd.c.orig	Mon Sep 30 02:58:36 2002
+++ src/stats-bsd.c	Sat Oct 19 22:50:30 2002
@@ -41,139 +41,171 @@
 #include "upclient.h"
 #include "options.h"
 #include "stats.h"
-#include "uplog.h" /* wrapper for <syslog.h> */
 
 /* System includes */
-#include <kvm.h>
-#include <stdio.h>
+#include <err.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <kvm.h>
 #include <limits.h>
-#include <sys/time.h>
-#include <sys/param.h>
+#include <stdio.h>
+#include <syslog.h>
 #include <sys/dkstat.h>
+#include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/time.h>
 #include <sys/utsname.h>
 
 /**
  * @desc	Get statistics
  */
-void getstats(unsigned long *puptime, double *pload, int *pidle, char *os, char *oslevel, char *cpu) {
-    struct utsname uts;
-    struct timeval boottime;
+void
+getstats(unsigned long *puptime, double *pload, int *pidle,
+	 char *os, char *oslevel, char *cpu)
+{
+  size_t size;
+  int mib[2];
+
+  {					/* ========== uptime ========== */
+    static struct timeval boottime;
+    static int initialized = 0;
     time_t now;
-    size_t size;
-    double loadavgs[2];
-    int mib[2];
-
-    /* Get uptime */
-    time(&now);
-    mib[0] = CTL_KERN;
-    mib[1] = KERN_BOOTTIME;
-    size = sizeof(boottime);
-    if (sysctl(mib, 2, &boottime, &size, NULL, 0) != -1 && (boottime.tv_sec != 0)) {
-        *puptime = now - boottime.tv_sec;
-        *puptime /= 60;
-    }
-
-    if (cfg_sendload) {
-        /* Get load average */
-        getloadavg(loadavgs, 3);
-        /* Use the 3rd element (15 minute load average) */
-        *pload = loadavgs[2];
-    }
-
-    if (cfg_sendos) {
-        /* Get os info */
-        uname(&uts);
-    }
-
-    if (cfg_sendcpu) {
-        /* Get CPU info */
-        mib[0] = CTL_HW;
-        if (cfg_sendcpulevel == 1) {
-            mib[1] = HW_MACHINE; /* Send architecture */
-        }
-        else {
-            mib[1] = HW_MODEL;   /* Send architecture's specific model */
-        }
-        size = CPU_SIZE;
-        sysctl(mib, 2, cpu, &size, NULL, 0);
-    }
-
-    if (cfg_sendos) {
-        strncpy(os, uts.sysname, OS_SIZE - 1);
-        if (cfg_sendoslevel) {
-            strncpy(oslevel, uts.release, OSLEVEL_SIZE - 1);
-        }
-    }
-
-    if (cfg_sendidle) {
-        static kvm_t *kp;
-        static int initialized = 0;
-        static struct nlist namelist [] = {
+
+    if (!initialized) {
+      initialized = 1;
+
+      mib[0] = CTL_KERN;
+      mib[1] = KERN_BOOTTIME;
+      size = sizeof(boottime);
+
+      if (sysctl(mib, 2, &boottime, &size, NULL, 0) == -1) {
+	uplog(LOG_ERR, "sysctl: kern.boottime");
+	err(1, "sysctl: kern.boottime");
+      }
+    }
+
+    if (boottime.tv_sec) {
+      time_t now;
+
+      time (&now);
+
+      *puptime = now - boottime.tv_sec;
+      *puptime /= 60;
+    }
+  }
+
+  if (cfg_sendload) {			/* ========== loadavg ========== */
+    double loadavgs[3] = { 0. };
+
+    getloadavg(loadavgs, 3);
+    /* Use the 3rd element (15 minute load average) */
+    *pload = loadavgs[2];
+  }
+
+  if (cfg_sendcpu) {			/* ========== cpu ========== */
+    static char buf[CPU_SIZE] = "";
+    static int initialized = 0;
+
+    if (!initialized) {
+      initialized = 1;
+
+      mib[0] = CTL_HW;
+      if (cfg_sendcpulevel == 1)
+	mib[1] = HW_MACHINE; /* Send architecture */
+      else
+	mib[1] = HW_MODEL;   /* Send architecture's specific model */
+      size = CPU_SIZE;
+
+      if (sysctl(mib, 2, buf, &size, NULL, 0) == -1) {
+	uplog(LOG_WARNING, "sysctl: hw.model");
+	/* warn("sysctl: hw.model"); */
+      }
+    }
+
+    strlcpy(cpu, buf, CPU_SIZE);
+  }
+
+  if (cfg_sendos) {
+    static struct utsname uts;
+    static int initialized = 0;
+
+    if (!initialized) {
+      initialized = 1;
+	    
+      uname(&uts);
+    }
+
+    strlcpy(os, uts.sysname, OS_SIZE);
+
+    if (cfg_sendoslevel)
+      strlcpy(oslevel, uts.release, OSLEVEL_SIZE);
+  }
+
+  if (cfg_sendidle) {			/* ========== idle_time ========== */
+    static kvm_t *kp;
+    static int initialized = 0;
+    static struct nlist namelist[] = {
 #define X_CP_TIME 0
-        { "_cp_time" },
-        { NULL },
-        };
-
-        if (!initialized) {
-            char errbuf[_POSIX2_LINE_MAX];
-            initialized = 1;
-
-            setgid(getgid());
-
-            kp = kvm_openfiles(NULL, NULL, NULL, O_RDONLY, errbuf);
-
-            if (!kp) {
-                uplog(LOG_WARNING, "kvm_openfiles: %s. (Did you forget to start upclient as root?)", errbuf);
-//            warn("kvm_openfiles: %s", errbuf);
-            }
-            else if (kvm_nlist(kp,namelist) == -1) {
-                uplog(LOG_WARNING, "kvm_nlist: %s", kvm_geterr(kp));
-//            warn("kvm_nlist: %s", kvm_geterr(kp));
-            }
-        }
-
-        if (kp) {
-            long ctime[CPUSTATES];
-            static long stime[CPUSTATES];
-            static int first_time = 1;
-
-            if (first_time) {
-                first_time = 0;
-
-                if (kvm_read(kp, namelist[X_CP_TIME].n_value, stime, sizeof(stime)) == -1) {
-                    uplog(LOG_WARNING, "kvm_read: %s", kvm_geterr(kp));
-//                    warn("kvm_read: %s", kvm_geterr(kp));
-                }
-                else
-                    sleep(1); /* to avoid the initial 0 idle value */
-            }
-
-            if (kvm_read(kp, namelist[X_CP_TIME].n_value, ctime, sizeof(ctime)) == -1) {
-                uplog(LOG_WARNING, "kvm_read: %s", kvm_geterr(kp));
-//                warn("kvm_read: %s", kvm_geterr(kp));
-            }
-            else {
-                int state;
-                double time = 0.;
-
-                for(state = 0; state < CPUSTATES; state++)
-                    time += ctime[state] - stime[state];
-
-                if (time == 0.)
-                    time = 1.;
-
-                *pidle = (ctime[CP_IDLE] - stime[CP_IDLE]) * 100. / time;
-
-                for(state = 0; state < CPUSTATES; state++)
-                    stime[state] = ctime[state];
-            }
-        }
-        else {
-            cfg_sendidle = 0;
-        }
+      { "_cp_time" },
+      { NULL },
+    };
+
+    if (!initialized) {
+      char errbuf[_POSIX2_LINE_MAX];
+      initialized = 1;
+
+      setgid(getgid());
+
+      kp = kvm_openfiles(NULL,NULL,NULL,O_RDONLY,errbuf);
+
+      if (!kp) {
+	uplog(LOG_WARNING, "kvm_openfiles: %s",errbuf);
+	/* warn("kvm_openfiles: %s",errbuf); */
+      } else if (kvm_nlist(kp,namelist) == -1) {
+	uplog(LOG_WARNING, "kvm_nlist: %s",kvm_geterr(kp));
+	/* warn("kvm_nlist: %s",kvm_geterr(kp)); */
+      }
+    }
+
+    if (kp) {
+      long ctime[CPUSTATES];
+      static long stime[CPUSTATES];
+      static int first_time = 1;
+
+      if (first_time) {
+	first_time = 0;
+
+	if (kvm_read(kp, namelist[X_CP_TIME].n_value,
+		     stime, sizeof(stime)) == -1) {
+	  uplog(LOG_WARNING, "kvm_read: %s", kvm_geterr(kp));
+	  /* warn("kvm_read: %s", kvm_geterr(kp)); */
+	} else
+	  sleep(1); /* to avoid the initial 0 idle value */
+      }
+
+      if (kvm_read(kp, namelist[X_CP_TIME].n_value,
+		   ctime, sizeof(ctime)) == -1) {
+	 uplog(LOG_WARNING, "kvm_read: %s", kvm_geterr(kp));
+	 /* warn("kvm_read: %s", kvm_geterr(kp)); */
+      } else {
+	int state;
+	double time = 0.;
+
+	for (state = 0; state < CPUSTATES; state++)
+	  time += ctime[state] - stime[state];
+
+	if (time == 0.)
+	  time = 1.;
+
+	*pidle = (ctime[CP_IDLE] - stime[CP_IDLE]) * 100. / time;
+
+	for (state = 0; state < CPUSTATES; state++)
+	  stime[state] = ctime[state];
+      }
+    } else {
+      cfg_sendidle = 0;
     }
+  }
 }
-#endif /* PLATFORM_BSD */
+
+#endif /* PLATFORM_BSD */                                                       
