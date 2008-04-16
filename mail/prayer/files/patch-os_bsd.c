--- prayer/os_bsd.c.orig	2008-04-09 12:58:30.000000000 -0800
+++ prayer/os_bsd.c	2008-04-16 00:23:36.000000000 -0800
@@ -576,14 +576,7 @@
 void
 os_limit_vm(unsigned long x)
 {
-    struct rlimit rl;
-    rlim_t y = (rlim_t)x;
-
-    rl.rlim_cur = y;
-    rl.rlim_max = y;
-    if (setrlimit(RLIMIT_DATA, &rl) < 0) {
-	log_misc("setrlimit: Unable to set vm limit to %ld: %m", x);
-    }
+  /* Linux specific */
 }
 
 void
