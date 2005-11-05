--- mapping-protocol.c.orig	Tue May 17 17:14:35 2005
+++ mapping-protocol.c	Tue May 17 17:15:24 2005
@@ -24,6 +24,8 @@
  *          William Jon McCann <mccann@jhu.edu>
  */
 
+#include <sys/types.h>
+#include <sys/time.h>
 #include <unistd.h>
 #include <string.h>
 #include <fcntl.h>
