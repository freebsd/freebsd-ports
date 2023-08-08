--- src/milter.c.orig	2023-07-15 18:53:41 UTC
+++ src/milter.c
@@ -33,6 +33,7 @@
 #        include <unistd.h>
 #    endif
 #    include <string.h>
+#    include <strings.h>
 
 static char* milter_uri = NULL;
 static char* milter_path = NULL;
