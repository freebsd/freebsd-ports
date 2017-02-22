--- src/libexec/poudriere/cached/cached.c.orig	2017-02-20 23:37:27 UTC
+++ src/libexec/poudriere/cached/cached.c
@@ -26,6 +26,7 @@
 
 #include <sys/types.h>
 
+#include <inttypes.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <string.h>
