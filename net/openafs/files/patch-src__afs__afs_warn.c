diff --git a/src/afs/afs_warn.c b/src/afs/afs_warn.c
index d8bdddc..a04a98b 100644
--- a/src/afs/afs_warn.c
+++ b/src/afs/afs_warn.c
@@ -25,6 +25,8 @@
 # include <net/if.h>
 # if defined(AFS_SUN58_ENV)
 #  include <sys/varargs.h>
+# elif defined(AFS_FBSD_ENV)
+#  include <machine/stdarg.h>
 # else
 #  include <stdarg.h>
 # endif
