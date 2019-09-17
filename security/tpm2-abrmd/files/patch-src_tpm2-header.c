--- src/tpm2-header.c.orig	2019-08-22 04:36:24 UTC
+++ src/tpm2-header.c
@@ -4,7 +4,6 @@
  * All rights reserved.
  */
 #include <assert.h>
-#include <endian.h>
 #include <glib.h>
 #include <inttypes.h>
 #include <stddef.h>
@@ -13,6 +12,7 @@
 #include <tss2/tss2_tpm2_types.h>
 
 #include "tpm2-header.h"
+#include "util.h"
 
 /**
  * Extract the 'tag' field from the tpm command header. This is a
