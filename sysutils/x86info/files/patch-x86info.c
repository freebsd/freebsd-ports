--- x86info.c.orig	Sat Sep 24 17:33:38 2005
+++ x86info.c	Wed Oct  5 17:34:30 2005
@@ -11,6 +11,10 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
+#if __FreeBSD__ < 500000
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 
 #include "x86info.h"
 
@@ -175,6 +179,9 @@
 {
 	unsigned int i;
 	struct cpudata *cpu, *head=NULL, *tmp;
+#if __FreeBSD__ < 500000
+	size_t nr = sizeof(nrCPUs);
+#endif
 
 	parse_command_line(argc, argv);
 	if (!silent) {
@@ -194,7 +201,11 @@
 	if (need_root && !user_is_root)
 		printf ("Need to be root to use specified options.\n");
 
+#if __FreeBSD__ > 500000
 	nrCPUs = sysconf (_SC_NPROCESSORS_CONF);
+#else
+	sysctlbyname("hw.ncpu", &nrCPUs, &nr, NULL, 0);
+#endif
 
 	if (!silent) {
 		printf ("Found %u CPU", nrCPUs);
