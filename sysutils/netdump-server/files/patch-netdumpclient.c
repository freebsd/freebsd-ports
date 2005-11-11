--- netdumpclient.c.orig	Fri Sep  3 23:53:20 2004
+++ netdumpclient.c	Sat Mar 19 16:53:49 2005
@@ -5,7 +5,8 @@
 #include <syslog.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/vfs.h>
+#include <sys/param.h>
+#include <sys/mount.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -898,7 +899,7 @@
 	      if (tried_once)
 		syslog (LOG_ERR, "No space for dump image, even after calling netdump-nospace");
 	      else
-		syslog (LOG_ERR, "No space for dump image");
+		syslog (LOG_ERR, "No space for dump image, avail = %lld, need = %lld\n", buf.f_bavail, memdump_size);
 	      
 	      status_request (client, TRUE);
 	      g_free (file);
