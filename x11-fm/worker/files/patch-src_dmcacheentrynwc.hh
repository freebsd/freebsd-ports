--- src/dmcacheentrynwc.hh.orig	2015-01-08 18:44:53.000000000 +0300
+++ src/dmcacheentrynwc.hh	2015-01-20 14:58:29.000000000 +0300
@@ -25,6 +25,7 @@
 #include "wdefines.h"
 #include "nwc_dir.hh"
 #include <aguix/refcount.hh>
+#include <functional>
 
 class DirBookmarksSettings;
 class DirFilterSettings;
