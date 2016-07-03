--- restricted-plugin-ptw/aircrack-crypto.cc.orig	2016-07-02 18:06:10 UTC
+++ restricted-plugin-ptw/aircrack-crypto.cc
@@ -21,6 +21,7 @@
 #include <string.h>
 #include <arpa/inet.h>
 #include <assert.h>
+#include <stdint.h>
 #include "aircrack-crypto.h"
 #include "aircrack-crctable.h"
 #include "aircrack-ptw2-lib.h"
