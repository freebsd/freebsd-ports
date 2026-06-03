--- src/ucm/util/log.c.orig	2026-02-04 09:52:46 UTC
+++ src/ucm/util/log.c
@@ -13,6 +13,7 @@
 
 #include <ucs/sys/compiler.h>
 #include <ucs/sys/string.h>
+#include <ucs/sys/sys.h>
 #include <sys/time.h>
 #include <string.h>
 #include <stdlib.h>
@@ -23,12 +24,21 @@
 #include <ctype.h>
 #include <errno.h>
 #include <limits.h>
+#if defined(__FreeBSD__)
+#include <sys/thr.h>
+#include <sys/syscall.h>
+#else
 #include <syscall.h>
+#endif
 
 #define UCM_LOG_BUF_SIZE   512
 
 static int  ucm_log_fileno                  = 1; /* stdout */
+#if defined(__FreeBSD__)
+static char ucm_log_hostname[UCS_HOST_NAME_MAX] = {0};
+#else
 static char ucm_log_hostname[HOST_NAME_MAX] = {0};
+#endif
 
 const char *ucm_log_level_names[] = {
     [UCS_LOG_LEVEL_FATAL] = "FATAL",
@@ -47,7 +57,6 @@ const char *ucm_log_level_names[] = {
 #define UCM_LOG_LTOA_FLAG_LONG   UCS_BIT(2)  /* long number */
 #define UCM_LOG_LTOA_FLAG_PAD0   UCS_BIT(3)  /* pad with zeroes */
 #define UCM_LOG_LTOA_PAD_LEFT    UCS_BIT(4)  /* pad to left */
-
 
 static char *ucm_log_add_padding(char *p, char *end, int pad, char fill)
 {
