
$FreeBSD$

--- channels/chan_h323.c	2004/10/10 13:00:17	1.1
+++ channels/chan_h323.c	2004/10/10 13:00:39
@@ -26,7 +26,7 @@
  * Version Info: $Id: patch-channels::chan_h323.c,v 1.3.2.3 2004/10/14 14:30:13 sobomax Exp $
  */
 
-
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/signal.h>
 #include <sys/param.h>
