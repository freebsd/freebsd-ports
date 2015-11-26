--- src/display/window_file_list.cc.orig	2014-05-14 14:30:51 UTC
+++ src/display/window_file_list.cc
@@ -36,6 +36,7 @@
 
 #include "config.h"
 
+#include <locale>
 #include <stdio.h>
 #include <torrent/path.h>
 #include <torrent/data/file.h>
