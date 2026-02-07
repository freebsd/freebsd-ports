--- usr/sbin/pkcsslotd/pkcsslotd.h.orig	2018-11-16 14:53:03 UTC
+++ usr/sbin/pkcsslotd/pkcsslotd.h
@@ -17,6 +17,9 @@
 #ifndef _PKCSSLOTMGR_H
 #define _PKCSSLOTMGR_H  1
 
+#include <sys/types.h>
+#include <sys/ipc.h>
+
 /***********
  * Defines *
  ***********/
