--- src/http.h.orig	2018-12-06 04:14:58 UTC
+++ src/http.h
@@ -29,6 +29,6 @@
 #include <stdio.h>
 #include "protocol.h"
 
-const struct Protocol *const http_protocol;
+extern const struct Protocol *const http_protocol;
 
 #endif
