--- x86info.c.orig	Mon Oct 15 02:04:23 2001
+++ x86info.c	Mon Oct 15 02:06:27 2001
@@ -11,6 +11,10 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
+#ifndef linux
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#endif
 #include "x86info.h"
 
 int show_msr=0;
@@ -89,7 +93,21 @@
 		return(0);
 	}
 
+#if defined _SC_NPROCESSORS	/* linux */
 	nrCPUs = sysconf (_SC_NPROCESSORS_CONF);
+#elif defined HW_NCPU   /* bsd */
+	{
+		int mib[2] = { CTL_HW, HW_NCPU };
+		size_t len;
+
+		len = sizeof(nrCPUs);
+		sysctl(mib, 2, &nrCPUs, &len, NULL, 0);
+	}
+#else
+	/* unknown interface to count cpu's */
+	nrCPUs=1;
+#endif
+
 	printf ("Found %d CPU", nrCPUs);
 	if (nrCPUs > 1)
 		printf ("s");
