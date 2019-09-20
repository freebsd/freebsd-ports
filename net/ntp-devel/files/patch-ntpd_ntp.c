--- ntpd/ntpd.c.orig	2019-06-07 01:59:15.000000000 -0700
+++ ntpd/ntpd.c	2019-09-20 12:13:28.810552000 -0700
@@ -999,7 +999,7 @@
 # if defined(HAVE_MLOCKALL)
 #  ifdef HAVE_SETRLIMIT
 	ntp_rlimit(RLIMIT_STACK, DFLT_RLIMIT_STACK * 4096, 4096, "4k");
-#   ifdef RLIMIT_MEMLOCK
+#   if defined(RLIMIT_MEMLOCK) && defined(DFLT_RLIMIT_MEMLOCK) && DFLT_RLIMIT_MEMLOCK != -1
 	/*
 	 * The default RLIMIT_MEMLOCK is very low on Linux systems.
 	 * Unless we increase this limit malloc calls are likely to
