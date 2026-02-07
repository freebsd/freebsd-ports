--- usr/lib/common/mech_ec.c.orig	2022-04-25 11:04:51 UTC
+++ usr/lib/common/mech_ec.c
@@ -14,7 +14,11 @@
  */
 
 #define _GNU_SOURCE
+#if !defined(__FreeBSD__)
 #include <endian.h>
+#else
+#include <sys/endian.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
