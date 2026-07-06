--- airframe/src/airdaemon.c.orig	2026-03-19 20:13:51 UTC
+++ airframe/src/airdaemon.c
@@ -43,6 +43,10 @@
 #include <airframe/airopt.h>
 #include <airframe/logconfig.h>
 
+#ifdef G_OS_UNIX
+#include <sys/wait.h>
+#endif
+
 static uint32_t       ad_retry_min        = 30;
 static uint32_t       ad_retry_max        = 0;
 static gboolean       ad_nodaemon         = FALSE;
