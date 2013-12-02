--- conkeror/conkeror-spawn-helper.c.orig   2013-08-16 13:08:22.000000000 -0300
+++ conkeror-spawn-helper.c   2013-11-03 22:48:41.000000000 -0400
@@ -5,6 +5,7 @@
  * COPYING file.
  **/
 
+#include <arpa/inet.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <unistd.h>
