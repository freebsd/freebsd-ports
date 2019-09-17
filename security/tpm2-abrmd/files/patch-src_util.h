--- src/util.h.orig	2019-08-22 19:25:53 UTC
+++ src/util.h
@@ -9,8 +9,17 @@
 #include <glib.h>
 #include <gio/gio.h>
 #include <tss2/tss2_tpm2_types.h>
+#if defined(__FreeBSD__)
+#include <sys/endian.h>
+#endif
 
 #include "control-message.h"
+
+#if defined(__FreeBSD__)
+#ifndef POLLRDHUP
+#define POLLRDHUP 0
+#endif
+#endif
 
 /* Use to suppress "unused parameter" warnings: */
 #define UNUSED_PARAM(p) ((void)(p))
