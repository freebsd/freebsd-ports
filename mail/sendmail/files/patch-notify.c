--- libsm/notify.c.orig	2020-05-19 19:54:32 UTC
+++ libsm/notify.c
@@ -10,11 +10,6 @@
 
 #include <sm/gen.h>
 
-#include <sm/conf.h>	/* FDSET_CAST */
-#include <sm/fdset.h>
-#include <sm/assert.h>
-#include <sm/notify.h>
-
 #include <sys/types.h>
 #include <signal.h>
 #include <stdio.h>
@@ -24,6 +19,11 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <string.h>	/* for memset() */
+
+#include <sm/conf.h>	/* FDSET_CAST */
+#include <sm/fdset.h>
+#include <sm/assert.h>
+#include <sm/notify.h>
 
 #if SM_NOTIFY_DEBUG
 #define SM_DBG(p)	fprintf p
