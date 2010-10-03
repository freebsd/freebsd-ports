--- plugin-ptw/aircrack-crypto.cc.orig	2010-05-24 11:40:15.000000000 +0200
+++ plugin-ptw/aircrack-crypto.cc	2010-05-24 11:39:34.000000000 +0200
@@ -21,6 +21,7 @@
 #include <string.h>
 #include <arpa/inet.h>
 #include <assert.h>
+#include <stdint.h>
 #include "aircrack-crypto.h"
 #include "aircrack-crctable.h"
 #include "aircrack-ptw2-lib.h"
