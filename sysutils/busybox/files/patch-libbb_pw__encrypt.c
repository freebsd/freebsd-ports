--- libbb/pw_encrypt.c.orig	2021-01-01 13:30:02 UTC
+++ libbb/pw_encrypt.c
@@ -7,7 +7,9 @@
  * Licensed under GPLv2 or later, see file LICENSE in this source tree.
  */
 #if !ENABLE_USE_BB_CRYPT
+#ifndef __FreeBSD__
 #include <crypt.h>
+#endif
 #endif
 #include "libbb.h"
 
