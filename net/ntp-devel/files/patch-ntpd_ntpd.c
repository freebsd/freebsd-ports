--- ntpd/ntpd.c.orig	2019-06-07 01:59:15.000000000 -0700
+++ ntpd/ntpd.c	2019-11-15 08:06:37.290504000 -0800
@@ -138,6 +138,17 @@
 # include <seccomp.h>
 #endif /* LIBSECCOMP and KERN_SECCOMP */
 
+#ifdef __FreeBSD__
+#include <sys/procctl.h>
+#ifndef PROC_STACKGAP_CTL
+/*
+ * Even if we compile on an older system we can still run on a newer one.
+ */
+#define	PROC_STACKGAP_CTL	17
+#define	PROC_STACKGAP_DISABLE	0x0002
+#endif
+#endif
+
 #ifdef HAVE_DNSREGISTRATION
 # include <dns_sd.h>
 DNSServiceRef mdns;
@@ -402,6 +413,18 @@
 	char *argv[]
 	)
 {
+#ifdef __FreeBSD__
+	{
+		/*
+		 * We Must disable ASLR stack gap on FreeBSD to avoid a
+		 * segfault. See PR/241421 and PR/241960.
+		 */
+		int aslr_var = PROC_STACKGAP_DISABLE;
+
+		pid_t my_pid = getpid();
+		procctl(P_PID, my_pid, PROC_STACKGAP_CTL, &aslr_var); 
+	}
+#endif
 	return ntpdmain(argc, argv);
 }
 #endif /* !SYS_WINNT */
@@ -999,7 +1022,7 @@
 # if defined(HAVE_MLOCKALL)
 #  ifdef HAVE_SETRLIMIT
 	ntp_rlimit(RLIMIT_STACK, DFLT_RLIMIT_STACK * 4096, 4096, "4k");
-#   ifdef RLIMIT_MEMLOCK
+#   if defined(RLIMIT_MEMLOCK) && defined(DFLT_RLIMIT_MEMLOCK) && DFLT_RLIMIT_MEMLOCK != -1
 	/*
 	 * The default RLIMIT_MEMLOCK is very low on Linux systems.
 	 * Unless we increase this limit malloc calls are likely to
