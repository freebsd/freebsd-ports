--- src/plugins/cli_filter/user_defaults/cli_filter_user_defaults.c.orig	2020-04-02 16:01:45 UTC
+++ src/plugins/cli_filter/user_defaults/cli_filter_user_defaults.c
@@ -44,6 +44,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "slurm/slurm_errno.h"
 #include "src/common/slurm_xlator.h"
