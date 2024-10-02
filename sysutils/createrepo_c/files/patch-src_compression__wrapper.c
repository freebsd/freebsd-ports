--- src/compression_wrapper.c.orig	2024-08-14 21:41:31 UTC
+++ src/compression_wrapper.c
@@ -35,6 +35,7 @@
 #include "error.h"
 #include "compression_wrapper.h"
 #include <zstd.h>
+#include <unistd.h>  // FreeBSD: Add STDOUT_FILENO
 
 
 #define ERR_DOMAIN                      CREATEREPO_C_ERROR
