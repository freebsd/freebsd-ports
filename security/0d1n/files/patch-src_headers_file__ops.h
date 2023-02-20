--- src/headers/file_ops.h.orig	2023-02-20 12:35:55 UTC
+++ src/headers/file_ops.h
@@ -12,7 +12,6 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <errno.h>
-#include <alloca.h>
 #include "opt_extract.h"
 
 void end_datatable(char * path);
