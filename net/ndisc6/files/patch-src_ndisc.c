--- src/ndisc.c.old	Thu Aug 17 18:06:30 2006
+++ src/ndisc.c	Thu Aug 17 18:06:42 2006
@@ -36,6 +36,7 @@
 #include <poll.h> /* poll() */
 #include <sys/socket.h>
 #include <fcntl.h>
+#include <sys/uio.h>
 
 #include "gettime.h"
 
