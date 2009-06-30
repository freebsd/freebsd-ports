Index: bgpd/printconf.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/printconf.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/printconf.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/printconf.c	30 Jun 2009 06:40:07 -0000	1.2
@@ -19,6 +19,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif
 
 #include "bgpd.h"
 #include "mrt.h"
