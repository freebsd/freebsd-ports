--- printing/backend/print_backend_cups.cc.orig	2016-08-03 19:02:22 UTC
+++ printing/backend/print_backend_cups.cc
@@ -4,6 +4,7 @@
 
 #include "printing/backend/print_backend.h"
 
+#include <cups/ppd.h>
 #include <dlfcn.h>
 #include <errno.h>
 #include <pthread.h>
