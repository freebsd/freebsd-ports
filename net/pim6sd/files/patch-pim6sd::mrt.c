--- pim6sd/mrt.c	Tue Nov 19 03:18:42 2002
+++ pim6sd/mrt.c	Tue Nov 19 03:18:26 2002
@@ -48,6 +48,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/param.h>
 #include <net/if.h>
 #include <net/route.h>
 #include <netinet/in.h>
