This patch now contains:
from bag@ua.net - correct free space check (without root's 10%)

--- btrspc.c.orig	Sun Mar  5 21:32:24 1995
+++ btrspc.c	Sun Jan 12 12:33:16 1997
@@ -98,13 +98,16 @@
 #define blkavail(fs)	((int)((fs).fd_req.bfreen))
 #define filavail(fs)	((int)((fs).fd_req.gfree))
 
-#elif defined(__bsdi__)
+#elif defined(__bsdi__) || defined(__FreeBSD__)
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
 #include <sys/mount.h>
 	typedef struct statfs	statfs_type;
 #define statfilesys		statfs
 #define bombed(call)	((call) < 0)
-#define blkavail(fs)	((int)((fs).f_bfree))
-#define filavail(fs)	((int)((fs).f_ffree))
+#define blkavail(fs)	((long)((fs).f_bavail))
+#define filavail(fs)	((long)((fs).f_ffree))
 
 #elif defined(SVR3)
 #include <ustat.h>
