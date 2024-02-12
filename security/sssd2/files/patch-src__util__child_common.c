--- src/util/child_common.c.orig	2024-01-12 12:05:40 UTC
+++ src/util/child_common.c
@@ -28,7 +28,6 @@
 #include <tevent.h>
 #include <sys/wait.h>
 #include <errno.h>
-#include <sys/prctl.h>
 
 #include "util/util.h"
 #include "util/find_uid.h"
@@ -806,8 +805,8 @@ static errno_t prepare_child_argv(TALLOC_CTX *mem_ctx,
             goto fail;
         }
 
-        argv[--argc] = talloc_asprintf(argv, "--dumpable=%d",
-                                           prctl(PR_GET_DUMPABLE));
+        argv[--argc] = talloc_asprintf(argv, "--dumpable=%d", 0);
+
         if (argv[argc] == NULL) {
             ret = ENOMEM;
             goto fail;
