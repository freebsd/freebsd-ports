--- libbb/pw_encrypt.c.orig	2018-12-05 14:44:34 UTC
+++ libbb/pw_encrypt.c
@@ -6,7 +6,7 @@
  *
  * Licensed under GPLv2 or later, see file LICENSE in this source tree.
  */
-#include <crypt.h>
+#include <unistd.h>
 #include "libbb.h"
 
 /* static const uint8_t ascii64[] ALIGN1 =
