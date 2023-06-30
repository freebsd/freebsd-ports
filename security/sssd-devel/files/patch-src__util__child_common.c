--- src/util/child_common.c.orig	2023-05-05 08:11:07 UTC
+++ src/util/child_common.c
@@ -28,7 +28,6 @@
 #include <tevent.h>
 #include <sys/wait.h>
 #include <errno.h>
-#include <sys/prctl.h>
 
 #include "util/util.h"
 #include "util/find_uid.h"
@@ -792,8 +791,8 @@ static errno_t prepare_child_argv(TALLOC_CTX *mem_ctx,
             goto fail;
         }
 
-        argv[--argc] = talloc_asprintf(argv, "--dumpable=%d",
-                                           prctl(PR_GET_DUMPABLE));
+        argv[--argc] = talloc_asprintf(argv, "--dumpable=%d", 0);
+
         if (argv[argc] == NULL) {
             ret = ENOMEM;
             goto fail;
