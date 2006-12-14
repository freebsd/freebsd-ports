--- xbattbar.c.orig	Fri Feb  2 13:25:29 2001
+++ xbattbar.c	Wed Dec 13 00:35:49 2006
@@ -501,6 +501,10 @@
 
 #ifdef __FreeBSD__
 
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
+#if defined(__i386__)
 #include <machine/apm_bios.h>
 
 #define APMDEV21       "/dev/apm0"
@@ -515,54 +519,90 @@
 #define        APM_STAT_BATT_LOW       1
 #define        APM_STAT_BATT_CRITICAL  2
 #define        APM_STAT_BATT_CHARGING  3
+#endif /* i386 */
 
 int first = 1;
 void battery_check(void)
 {
-  int fd, r, p;
-  struct apm_info     info;
+  int r, p;
+  static int sysctl = 1;
 
-  if ((fd = open(APMDEV21, O_RDWR)) == -1 &&
-      (fd = open(APMDEV22, O_RDWR)) == -1) {
-    fprintf(stderr, "xbattbar: cannot open apm device\n");
-    exit(1);
-  }
-  if (ioctl(fd, APMIO_GETINFO, &info) == -1) {
-    fprintf(stderr, "xbattbar: ioctl APMIO_GETINFO failed\n");
-    exit(1);
+  if (sysctl) {
+    size_t r_size, p_size;
+
+    /* get current status */
+    r_size = sizeof(r);
+    if (sysctl && sysctlbyname("hw.acpi.battery.life", &r, &r_size, NULL, 0) == -1) {
+#if defined(__i386__)
+      fprintf(stderr, "xbattbar: fall back to apm interface\n");
+      sysctl = 0;
+#else /* !i386 */
+      fprintf(stderr, "xbattbar: can not get battery status\n");
+      exit(1);
+#endif /* i386 */
+    }
+
+    /* get AC-line status */
+    p_size = sizeof(p);
+    if (sysctl && sysctlbyname("hw.acpi.acline", &p, &p_size, NULL, 0) == -1) {
+#if defined(__i386__)
+      fprintf(stderr, "xbattbar: fall back to apm interface\n");
+      sysctl = 0;
+#else /* !i386 */
+      fprintf(stderr, "xbattbar: can not get AC-line status\n");
+      exit(1);
+#endif /* i386 */
+    }
   }
-  close (fd);
 
-  ++elapsed_time;
+#if defined(__i386__)
+  if (!sysctl) {
+    int fd;
+    struct apm_info info;
+
+    if ((fd = open(APMDEV21, O_RDONLY)) == -1 &&
+        (fd = open(APMDEV22, O_RDONLY)) == -1) {
+      fprintf(stderr, "xbattbar: cannot open apm device\n");
+      exit(1);
+    }
+    if (ioctl(fd, APMIO_GETINFO, &info) == -1) {
+      fprintf(stderr, "xbattbar: ioctl APMIO_GETINFO failed\n");
+      exit(1);
+    }
+    close (fd);
 
-  /* get current status */
-  if (info.ai_batt_life == APM_STAT_UNKNOWN) {
-    switch (info.ai_batt_stat) {
-    case APM_STAT_BATT_HIGH:
-      r = 100;
-      break;
-    case APM_STAT_BATT_LOW:
-      r = 40;
-      break;
-    case APM_STAT_BATT_CRITICAL:
-      r = 10;
-      break;
-    default:        /* expected to be APM_STAT_UNKNOWN */
+    /* get current status */
+    if (info.ai_batt_life == APM_STAT_UNKNOWN) {
+      switch (info.ai_batt_stat) {
+      case APM_STAT_BATT_HIGH:
+        r = 100;
+        break;
+      case APM_STAT_BATT_LOW:
+        r = 40;
+        break;
+      case APM_STAT_BATT_CRITICAL:
+        r = 10;
+        break;
+      default:        /* expected to be APM_STAT_UNKNOWN */
+        r = 100;
+      }
+    } else if (info.ai_batt_life > 100) {
+      /* some APM BIOSes return values slightly > 100 */
       r = 100;
+    } else {
+      r = info.ai_batt_life;
     }
-  } else if (info.ai_batt_life > 100) {
-    /* some APM BIOSes return values slightly > 100 */
-    r = 100;
-  } else {
-    r = info.ai_batt_life;
-  }
 
-  /* get AC-line status */
-  if (info.ai_acline == APM_STAT_LINE_ON) {
-    p = APM_STAT_LINE_ON;
-  } else {
-    p = APM_STAT_LINE_OFF;
+    /* get AC-line status */
+    if (info.ai_acline == APM_STAT_LINE_ON) {
+      p = APM_STAT_LINE_ON;
+    } else {
+      p = APM_STAT_LINE_OFF;
+    }
   }
+#endif /* i386 */
+
+  ++elapsed_time;
 
   if (first || ac_line != p || battery_level != r) {
     first = 0;
