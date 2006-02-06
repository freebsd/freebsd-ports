
$FreeBSD$

--- channels/chan_h323.c.orig
+++ channels/chan_h323.c
@@ -31,6 +31,7 @@
  * \ingroup channel_drivers
  */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/signal.h>
 #include <sys/param.h>
