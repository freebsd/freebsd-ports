--- drivers/main.h.orig	2015-12-29 04:08:34.000000000 -0800
+++ drivers/main.h	2020-11-13 23:40:47.007315000 -0800
@@ -1,6 +1,7 @@
 #ifndef MAIN_H
 #define MAIN_H
 
+#include <sys/param.h>
 #include "common.h"
 #include "upsconf.h"
 #include "dstate.h"
