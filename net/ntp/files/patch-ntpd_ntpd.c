--- ntpd/ntpd.c.orig	2020-06-23 02:17:48.000000000 -0700
+++ ntpd/ntpd.c	2021-10-16 07:59:32.497688000 -0700
@@ -145,7 +145,7 @@
 # include <seccomp.h>
 #endif /* LIBSECCOMP and KERN_SECCOMP */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD_version) && __FreeBSD_version < 1400037
 #include <sys/procctl.h>
 #ifndef PROC_STACKGAP_CTL
 /*
@@ -438,7 +438,7 @@
 	char *argv[]
 	)
 {
-#   ifdef __FreeBSD__
+#   if defined(__FreeBSD_version) && __FreeBSD_version < 1400037
 	{
 		/*
 		 * We Must disable ASLR stack gap on FreeBSD to avoid a
