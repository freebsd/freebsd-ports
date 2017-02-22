diff --git src/libexec/poudriere/cached/cached.c src/libexec/poudriere/cached/cached.c
index 68ba6e6..ce266cd 100644
--- src/libexec/poudriere/cached/cached.c
+++ src/libexec/poudriere/cached/cached.c
@@ -26,6 +26,7 @@
 
 #include <sys/types.h>
 
+#include <inttypes.h>
 #include <unistd.h>
 #include <stdio.h>
 #include <string.h>
