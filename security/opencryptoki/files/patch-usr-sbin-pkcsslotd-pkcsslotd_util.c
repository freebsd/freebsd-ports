--- usr/sbin/pkcsslotd/pkcsslotd_util.c.orig	2022-04-25 11:04:51 UTC
+++ usr/sbin/pkcsslotd/pkcsslotd_util.c
@@ -11,6 +11,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
+#include <pthread.h>
 
 #include "slotmgr.h"
 #include "log.h"
