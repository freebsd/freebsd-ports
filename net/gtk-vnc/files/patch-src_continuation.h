--- src/continuation.h.orig	2025-02-07 09:45:55 UTC
+++ src/continuation.h
@@ -23,6 +23,7 @@
 
 #include <stddef.h>
 #include <setjmp.h>
+#include <sys/types.h>
 
 struct continuation
 {
