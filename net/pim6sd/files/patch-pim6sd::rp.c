--- pim6sd/rp.c	Tue Nov 19 03:20:02 2002
+++ pim6sd/rp.c	Tue Nov 19 03:19:50 2002
@@ -76,6 +76,7 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/param.h>
 #include <net/if.h>
 #include <net/route.h>
 #include <netinet/in.h>
