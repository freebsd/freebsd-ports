--- src/findlib/fstype.c.orig	2015-08-13 13:52:24 UTC
+++ src/findlib/fstype.c
@@ -31,7 +31,9 @@
 #include "find.h"
 #include <sys/types.h>
 #include <sys/stat.h>
-
+#ifdef HAVE_SUN_OS
+  #include <sys/mnttab.h>
+#endif
 #else /* Set up for testing a stand alone program */
 
 #include <stdio.h>
@@ -373,7 +375,7 @@ bool read_mtab(mtab_handler_t *mtab_hand
       mtab_handler(user_ctx, &st, mnt.mnt_fstype, mnt.mnt_mountp,
          mnt.mnt_mntopts, mnt.mnt_special);
    }
-   fclose(fp);
+   fclose(mntfp);
    V(mutex);
 #endif
 
