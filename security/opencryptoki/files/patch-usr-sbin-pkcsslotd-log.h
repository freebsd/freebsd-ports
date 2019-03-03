--- usr/sbin/pkcsslotd/log.h.orig	2018-11-16 14:53:03 UTC
+++ usr/sbin/pkcsslotd/log.h
@@ -11,6 +11,9 @@
 #ifndef _LOG_H
 #define _LOG_H 1
 
+#include <sys/types.h>
+#include <unistd.h>
+
 #ifndef FALSE
 #define FALSE 0
 #endif                          /* FALSE */
