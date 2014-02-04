--- ./src/lib/3rdparty/processinfo.h.orig	2014-01-26 19:04:16.000000000 +0330
+++ ./src/lib/3rdparty/processinfo.h	2014-01-26 19:04:33.000000000 +0330
@@ -18,6 +18,8 @@
 #ifndef PROCESSINFO_H
 #define PROCESSINFO_H
 
+#include <unistd.h>
+
 #include <QString>
 
 #include "qz_namespace.h"
