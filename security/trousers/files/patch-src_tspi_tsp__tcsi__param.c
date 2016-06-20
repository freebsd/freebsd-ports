--- src/tspi/tsp_tcsi_param.c.orig	2016-06-20 15:21:26 UTC
+++ src/tspi/tsp_tcsi_param.c
@@ -11,7 +11,12 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
+#if !defined(__FreeBSD__)
 #include <bits/local_lim.h>
+#else
+#include <sys/param.h>
+#define	HOST_NAME_MAX	MAXHOSTNAMELEN
+#endif
 #include "trousers/tss.h"
 #include "trousers/trousers.h"
 #include "trousers_types.h"
