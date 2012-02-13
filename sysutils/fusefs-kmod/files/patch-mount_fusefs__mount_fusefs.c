--- mount_fusefs/mount_fusefs.c	2008-02-05 07:25:57.000000000 +0200
+++ mount_fusefs/mount_fusefs.c	2012-01-07 21:07:35.000000000 +0200
@@ -44,6 +44,7 @@
 #include <getopt.h>
 #include <libgen.h>
 #include <limits.h>
+#include <osreldate.h>
 #include <paths.h>
 
 #include "fuse4bsd.h"
@@ -312,7 +313,12 @@
 	 * Resolve the mountpoint with realpath(3) and remove unnecessary
 	 * slashes from the devicename if there are any.
 	 */
+#if __FreeBSD_version >= 1000005
+	if (checkpath(dir, mntpath) != 0)
+		err(1, "%s", mntpath);
+#else
 	(void)checkpath(dir, mntpath);
+#endif
 	(void)rmslashes(dev, dev);
 
 	if (strcmp(dev, "auto") == 0)
