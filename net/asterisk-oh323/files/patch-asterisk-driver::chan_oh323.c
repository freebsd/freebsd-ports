--- asterisk-driver/chan_oh323.c.orig	Wed Jan 18 11:25:02 2006
+++ asterisk-driver/chan_oh323.c	Wed Jan 18 11:37:09 2006
@@ -43,10 +43,12 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <math.h>
+#include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <sys/signal.h>
+#include <stdio.h>
 
-#include "asterisk.h"
+//#include "asterisk.h"
 
 #include "asterisk/lock.h"
 #include "asterisk/channel.h"
@@ -4429,7 +4431,7 @@ static int kill_monitor(void)
 				return(-1);
 			}
 		}
-		monitor_thread = -2;
+		monitor_thread = AST_PTHREADT_STOP;
 	} else {
 		ast_log(LOG_WARNING, "Unable to lock the monitor.\n");
 		return(-1);
