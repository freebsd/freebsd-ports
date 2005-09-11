--- common/cvsync.h.orig	Mon Jun  7 14:33:25 2004
+++ common/cvsync.h	Sun Sep 11 03:34:22 2005
@@ -30,6 +30,8 @@
 #ifndef __CVSYNC_H__
 #define	__CVSYNC_H__
 
+#include <sys/types.h>
+
 #define	CVSYNC_MAXCMDLEN	2048
 #define	CVSYNC_MAXADDRLEN	128
 
