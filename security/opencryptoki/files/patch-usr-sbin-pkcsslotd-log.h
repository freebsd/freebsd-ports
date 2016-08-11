--- usr/sbin/pkcsslotd/log.h.orig	2016-04-29 17:26:46 UTC
+++ usr/sbin/pkcsslotd/log.h
@@ -297,9 +297,8 @@
 #ifndef _LOG_H
 #define _LOG_H 1
 
-
-
-
+#include <sys/types.h>
+#include <unistd.h>
 
 #ifndef FALSE
 #define FALSE 0
