
$FreeBSD$

--- channels/chan_h323.c	2003/10/19 06:39:00	1.1
+++ channels/chan_h323.c	2003/10/19 06:52:18
@@ -54,6 +54,7 @@
 #include <fcntl.h>
 #include <netdb.h>
 #include <sys/signal.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 
 
