--- udpr-negotiate.c.orig	2007-05-25 12:01:59.000000000 +0200
+++ udpr-negotiate.c	2009-02-06 08:18:02.000000000 +0100
@@ -3,6 +3,10 @@
 #include <errno.h>
 #include <sys/stat.h>
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include "log.h"
 #include "socklib.h"
 #include "udpcast.h"
@@ -82,13 +86,13 @@
     if(disk_config->fileName != NULL) {
 	int oflags = O_CREAT | O_WRONLY;
 	if((disk_config->flags & FLAG_SYNC)) {
-	    oflags |= O_SYNC;
+	    oflags |= O_FSYNC;
 	} else if( !(disk_config->flags & FLAG_NOSYNC)) {
 	    struct stat buf;
 	    if(stat(disk_config->fileName, &buf) == 0) {
 		/* If target is device, open it synchronously */
 		if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
-			oflags |= O_SYNC;
+			oflags |= O_FSYNC;
 	    }
 	}
 	outFile = open(disk_config->fileName, oflags | O_BINARY, 0644);
