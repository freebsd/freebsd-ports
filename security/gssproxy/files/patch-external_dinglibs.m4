--- external/dinglibs.m4.orig	2026-10-20 15:29:35 UTC
+++ external/dinglibs.m4
@@ -13,7 +13,7 @@ AC_DEFUN([WITH_LIBINI_CONFIG],
 
     AC_RUN_IFELSE([AC_LANG_SOURCE([[
     /* See: https://pagure.io/SSSD/ding-libs/pull-request/3172 */
-    #include <linux/limits.h>
+    #include <limits.h>
     #include <string.h>
     #include <errno.h>
     #include <stdio.h>
