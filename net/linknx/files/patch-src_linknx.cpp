--- src/linknx.cpp.orig      2012-02-12 14:43:55.000000000 +0100
+++ src/linknx.cpp  2012-04-10 17:58:03.000000000 +0200
@@ -29,6 +29,7 @@
 #include <fcntl.h>
 #include <cstring>
 #include <pthsem.h>
+#include <sys/stat.h>
 #include "config.h"
 #include "ticpp.h"
 #include "eibclient.h"

