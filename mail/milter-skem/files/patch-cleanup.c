--- cleanup.c	Sun Jan  1 08:19:39 2006
+++ newcleanup.c	Sun Jan  1 08:19:18 2006
@@ -15,6 +15,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
+#include <inttypes.h>
 #include <dirent.h>
 #include <sys/stat.h>
 #include <sys/time.h>
@@ -50,9 +51,9 @@
 			return NULL;
 		}
 	}
-	syslog(LOG_DEBUG, "periodic cleanup: period %ld seconds%s, "
+	syslog(LOG_DEBUG, "periodic cleanup: period %jd seconds%s, "
 	    "permanent bans removed after %u seconds since last seen",
-	    O.cleanupperiod.tv_sec,
+	    (intmax_t)O.cleanupperiod.tv_sec,
 	    O.cleanupperiod.tv_sec ? "" : " (one shot)",
 	    O.permcleanup);
 	for (result = 0, select_failures = 0;
