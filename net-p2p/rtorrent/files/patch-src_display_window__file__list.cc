--- src/display/window_file_list.cc.orig	2012-02-14 04:32:01.000000000 +0100
+++ src/display/window_file_list.cc	2014-02-02 22:49:44.000000000 +0100
@@ -36,6 +36,7 @@
 
 #include "config.h"
 
+#include <locale>
 #include <stdio.h>
 #include <torrent/path.h>
 #include <torrent/data/file.h>
