--- external/dinglibs.m4.orig	2022-07-26 10:17:29 UTC
+++ external/dinglibs.m4
@@ -19,20 +19,19 @@ AC_DEFUN([WITH_REF_ARRAY], [
 
 AC_DEFUN([WITH_REF_ARRAY], [
 
-AC_CHECK_LIB(ref_array, ref_array_destroy, [],
+AC_CHECK_LIB(ini_config, ref_array_destroy, [],
              [AC_MSG_ERROR([library must support ref_array_destroy])],
              [$INI_CONFIG_LIBS])
 
 AC_RUN_IFELSE([AC_LANG_SOURCE([[
 /* See: https://pagure.io/SSSD/ding-libs/pull-request/3172 */
-#include <linux/limits.h>
+#include <limits.h>
 #include <string.h>
 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <ini_configobj.h>
-#include <ini_config.h>
 
 static int write_to_file(char *path, char *text)
 {
