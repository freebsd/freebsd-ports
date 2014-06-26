--- src/audacious/util.c.orig	2014-04-23 04:36:33.000000000 +0200
+++ src/audacious/util.c	2014-06-19 23:47:29.000000000 +0200
@@ -35,6 +35,9 @@
 
 #include <libaudcore/audstrings.h>
 
+#include <sys/types.h>
+#include <sys/sysctl.h>
+
 #include "debug.h"
 #include "i18n.h"
 #include "misc.h"
@@ -212,7 +215,19 @@
             return NULL;
     }
 #else
-    return NULL;
+    char path[PATH_MAX + 1];
+    size_t len = PATH_MAX + 1;
+    int mib[4];
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PATHNAME;
+    mib[3] = -1;
+
+    if (sysctl(mib, 4, &path, &len, NULL, 0) != 0)
+        return NULL;
+
+    return str_get (path);
 #endif
 }
 
