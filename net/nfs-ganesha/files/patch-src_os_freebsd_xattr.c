diff --git a/src/os/freebsd/xattr.c b/src/os/freebsd/xattr.c
index 5edb6f8b8..1d6275d61 100644
--- src/os/freebsd/xattr.c
+++ src/os/freebsd/xattr.c
@@ -26,6 +26,9 @@
  */
 
 #include <os/freebsd/xattr.h>
+#ifndef NAME_MAX
+#include <sys/syslimits.h>
+#endif
 #include <sys/extattr.h>
 
 #ifndef EXTATTR_MAXNAMELEN
