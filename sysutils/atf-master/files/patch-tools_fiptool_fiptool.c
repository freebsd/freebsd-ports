--- tools/fiptool/fiptool.c.orig	2023-09-22 09:29:57 UTC
+++ tools/fiptool/fiptool.c
@@ -4,6 +4,7 @@
  * SPDX-License-Identifier: BSD-3-Clause
  */
 
+#define __BSD_VISIBLE 1
 #ifndef _MSC_VER
 #include <sys/mount.h>
 #endif
