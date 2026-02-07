--- lmmon.c.orig	2015-05-01 23:15:27.977446000 +0200
+++ lmmon.c	2015-05-01 23:17:30.502831000 +0200
@@ -43,6 +43,7 @@
   #include "config.h"
 #endif
 #ifdef HAVE_SMB
+  #include <osreldate.h>
   #include <machine/smb.h>
 #endif
 
@@ -73,7 +74,12 @@
 
 		/* Initialize the struct */
 		bzero(&cmd, sizeof(cmd));
+#if (__FreeBSD_version >= 1100071)
+		cmd.rbuf = &byte;
+		cmd.rcount = 1;
+#else
 		cmd.data.byte_ptr = &byte;
+#endif		
 		cmd.slave         = 0x5a;
 		cmd.cmd           = command;
  
