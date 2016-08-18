--- libcpuid/cpuid_main.c.orig	2016-08-16 05:32:11 UTC
+++ libcpuid/cpuid_main.c
@@ -126,6 +126,7 @@ static int get_total_cpus(void)
 #endif
 
 #if defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__ || defined __bsdi__ || defined __QNX__
+#include <sys/types.h>
 #include <sys/sysctl.h>
 
 static int get_total_cpus(void)
