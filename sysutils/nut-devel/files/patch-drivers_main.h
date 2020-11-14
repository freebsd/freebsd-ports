--- drivers/main.h.orig	2020-11-13 23:48:39.471828000 -0800
+++ drivers/main.h	2020-11-13 23:49:42.830476000 -0800
@@ -1,6 +1,7 @@
 #ifndef MAIN_H
 #define MAIN_H
 
+#include <sys/errno.h>
 #include "common.h"
 #include "upsconf.h"
 #include "dstate.h"
