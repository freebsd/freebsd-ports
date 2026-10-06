--- cargo-crates/cubeb-sys-0.38.0/libcubeb/src/cubeb_alsa.c.orig	2026-10-02 18:06:31 UTC
+++ cargo-crates/cubeb-sys-0.38.0/libcubeb/src/cubeb_alsa.c
@@ -5,6 +5,7 @@
  * accompanying file LICENSE for details.
  */
 #undef NDEBUG
+#include <stdlib.h>
 #define _DEFAULT_SOURCE
 #define _BSD_SOURCE
 #if defined(__NetBSD__)
