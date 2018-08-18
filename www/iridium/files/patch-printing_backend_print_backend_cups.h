--- printing/backend/print_backend_cups.h.orig	2017-09-07 12:48:26.701906000 +0200
+++ printing/backend/print_backend_cups.h	2017-09-07 12:48:48.628278000 +0200
@@ -5,6 +5,8 @@
 #ifndef PRINTING_BACKEND_PRINT_BACKEND_CUPS_H_
 #define PRINTING_BACKEND_PRINT_BACKEND_CUPS_H_
 
+#include <cups/ppd.h>
+
 #include <string>
 
 #include "base/files/file_util.h"
