--- pim6sd/pim6_proto.c	Tue Nov 19 03:19:39 2002
+++ pim6sd/pim6_proto.c	Tue Nov 19 03:19:11 2002
@@ -103,6 +103,7 @@
  */
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/socket.h>
 #include <net/if.h>
 #include <net/route.h>
