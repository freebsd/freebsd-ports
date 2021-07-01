--- src/utils.c.orig	2021-07-01 13:24:17 UTC
+++ src/utils.c
@@ -24,6 +24,7 @@
 #include <regex.h>
 #include <ctype.h>
 #include <sys/select.h>
+#include <sys/wait.h>
 
 #ifdef USE_WCHAR
   #include <wchar.h>
