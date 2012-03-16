--- Unaccent.xs.orig	2004-12-29 02:45:18.000000000 -0900
+++ Unaccent.xs	2012-03-15 17:04:26.000000000 -0800
@@ -35,7 +35,7 @@
 #include "unac.h"
 
 static char* buffer;
-static int buffer_length;
+static size_t buffer_length;
 
 static void unac_debug_print(const char* message, void* data)
 {
