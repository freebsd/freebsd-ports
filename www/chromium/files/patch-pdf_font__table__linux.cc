--- pdf/font_table_linux.cc.orig	2021-09-28 13:14:28 UTC
+++ pdf/font_table_linux.cc
@@ -4,6 +4,7 @@
 
 #include "pdf/font_table_linux.h"
 
+#include <unistd.h>
 #include <sys/stat.h>
 
 #include <limits>
