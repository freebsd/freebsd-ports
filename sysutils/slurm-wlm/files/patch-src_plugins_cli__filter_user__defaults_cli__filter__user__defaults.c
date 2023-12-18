--- src/plugins/cli_filter/user_defaults/cli_filter_user_defaults.c.orig	2023-03-28 20:19:41 UTC
+++ src/plugins/cli_filter/user_defaults/cli_filter_user_defaults.c
@@ -45,6 +45,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "slurm/slurm_errno.h"
 #include "src/common/slurm_xlator.h"
