Index: bgpd/rde_attr.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_attr.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpd/rde_attr.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_attr.c	30 Jun 2009 06:40:07 -0000	1.2
@@ -17,7 +17,11 @@
  */
 
 #include <sys/types.h>
+#if defined(__FreeBSD__)	/* sys/hash.h */
+#include "hash.h"
+#else
 #include <sys/hash.h>
+#endif /* defined(__FreeBSD__) */
 #include <sys/queue.h>
 
 #include <netinet/in.h>
@@ -25,6 +29,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif /* defined(__FreeBSD__) */
 
 #include "bgpd.h"
 #include "rde.h"
