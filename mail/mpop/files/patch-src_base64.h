--- src/base64.h.orig	2026-06-27 11:26:35 UTC
+++ src/base64.h
@@ -19,6 +19,7 @@
 #define BASE64_H
 
 #include <stddef.h>
+#include <stdbool.h>
 typedef size_t idx_t;
 
 #ifdef __cplusplus
