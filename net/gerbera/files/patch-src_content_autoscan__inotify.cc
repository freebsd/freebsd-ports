--- src/content/autoscan_inotify.cc.orig	2021-08-30 21:46:08 UTC
+++ src/content/autoscan_inotify.cc
@@ -33,6 +33,7 @@
 #include "autoscan_inotify.h" // API
 
 #include <cassert>
+#include <sstream>
 
 #include "content_manager.h"
 #include "database/database.h"
