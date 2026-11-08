Index: lib/util/util_crypt.c
--- lib/util/util_crypt.c.orig	2026-01-20 15:42:54 UTC
+++ lib/util/util_crypt.c
@@ -4,6 +4,8 @@
 #include <talloc.h>
 #ifdef HAVE_CRYPT_H
 #include <crypt.h>
+#else
+#include <unistd.h>
 #endif
 #include "util_crypt.h"
 
