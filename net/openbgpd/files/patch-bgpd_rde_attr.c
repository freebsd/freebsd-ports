--- bgpd/rde_attr.c	2007-05-22 16:03:31.000000000 +0200
+++ bgpd/rde_attr.c	2008-03-18 15:30:31.000000000 +0100
@@ -17,7 +17,6 @@
  */
 
 #include <sys/types.h>
-#include <sys/hash.h>
 #include <sys/queue.h>
 
 #include <netinet/in.h>
@@ -28,6 +27,9 @@
 
 #include "bgpd.h"
 #include "rde.h"
+#include "hash.h"
+
+#include <limits.h>
 
 int
 attr_write(void *p, u_int16_t p_len, u_int8_t flags, u_int8_t type,
