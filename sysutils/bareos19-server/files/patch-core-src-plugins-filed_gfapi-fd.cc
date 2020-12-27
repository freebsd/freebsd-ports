--- core/src/plugins/filed/gfapi-fd.cc	2020-02-03 00:50:05.248044000 -0500
+++ core/src/plugins/filed/gfapi-fd.cc	2020-02-03 00:50:35.639144000 -0500
@@ -32,7 +32,7 @@
 #include "lib/berrno.h"
 #include "lib/edit.h"
 
-#include <api/glfs.h>
+#include <glusterfs/api/glfs.h>
 
 
 /* avoid missing config.h problem on Debian 8 and Ubuntu 16:
@@ -41,10 +41,10 @@
  */
 #ifndef _CONFIG_H
 #define _CONFIG_H
-#include <compat-errno.h>
+#include <glusterfs/compat-errno.h>
 #undef _CONFIG_H
 #else
-#include <compat-errno.h>
+#include <glusterfs/compat-errno.h>
 #endif
 
 namespace filedaemon {
