--- usr/sbin/pkcsslotd/pkcsslotd.h.orig	2016-04-29 17:26:46 UTC
+++ usr/sbin/pkcsslotd/pkcsslotd.h
@@ -305,6 +305,9 @@
 #ifndef _PKCSSLOTMGR_H
 #define _PKCSSLOTMGR_H 1
 
+#include <sys/types.h>
+#include <sys/ipc.h>
+
 /***********
  * Defines *
  ***********/
