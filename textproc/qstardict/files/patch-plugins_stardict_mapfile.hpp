--- plugins/stardict/mapfile.hpp.orig	2019-03-09 16:13:21 UTC
+++ plugins/stardict/mapfile.hpp
@@ -14,6 +14,7 @@
 #  include <windows.h>
 #endif
 #include <glib.h>
+#include <unistd.h>
 
 class MapFile
 {
