--- hdrecover.cpp.orig	2011-09-25 04:48:10.000000000 -0700
+++ hdrecover.cpp	2012-06-29 16:02:39.000000000 -0700
@@ -26,7 +26,11 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <unistd.h>
+#ifdef __FreeBSD_cc_version
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <errno.h>
 #include <string.h>
 #include <time.h>
@@ -260,7 +264,7 @@
 		sprintf(p, "%d seconds", remaining);
 	    }
 	    printf("Sector %Ld (%02d%%) ETR: %s\n",
-		   sectornum, (int) ((sectornum * 100) / length), rs);
+		   (long) sectornum, (long int) ((sectornum * 100) / length), rs);
 	}
     }
 
