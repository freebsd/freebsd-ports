Index: bgpd/rde_rib.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_rib.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/rde_rib.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_rib.c	30 Jun 2009 06:40:07 -0000	1.2
@@ -18,7 +18,11 @@
 
 #include <sys/types.h>
 #include <sys/queue.h>
+#if defined(__FreeBSD__)	/* sys/hash.h */
+#include "hash.h"
+#else
 #include <sys/hash.h>
+#endif /* defined(__FreeBSD__) */
 
 #include <stdlib.h>
 #include <string.h>
