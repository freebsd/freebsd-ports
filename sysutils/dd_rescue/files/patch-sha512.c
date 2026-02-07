--- sha512.c.orig	2024-08-22 17:41:01 UTC
+++ sha512.c
@@ -13,13 +13,14 @@
 #endif
 
 #include "sha512.h"
+#include "ffs.h"
 #include <stdint.h>
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
 #include <assert.h>
 #include <unistd.h>
-#include <endian.h>
+#include <machine/endian.h>
 
 #ifdef HAVE_SYS_REG_H
 #include <sys/reg.h>
