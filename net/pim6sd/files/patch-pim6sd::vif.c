--- pim6sd/vif.c	Tue Nov 19 03:18:11 2002
+++ pim6sd/vif.c	Tue Nov 19 03:17:44 2002
@@ -58,6 +58,7 @@
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
+#include <sys/param.h>
 #include <net/if.h>
 #include <net/route.h>
 #include <netinet/in.h>
