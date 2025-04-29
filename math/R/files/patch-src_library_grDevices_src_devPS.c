--- src/library/grDevices/src/devPS.c.orig	2025-04-29 02:15:09 UTC
+++ src/library/grDevices/src/devPS.c
@@ -29,6 +29,7 @@
 #include <ctype.h>
 #include <limits.h> /* required for MB_LEN_MAX */
 #include <string.h>
+#include <unistd.h>
 
 #include <wchar.h>
 #include <wctype.h>
