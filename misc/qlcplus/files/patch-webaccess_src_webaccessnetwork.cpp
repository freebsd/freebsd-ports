--- webaccess/src/webaccessnetwork.cpp.orig	2024-03-20 07:21:37 UTC
+++ webaccess/src/webaccessnetwork.cpp
@@ -25,6 +25,8 @@
 #include <QDebug>
 #include <QFile>
 
+#include <sys/socket.h>
+
 #include "webaccessnetwork.h"
 #include "commonjscss.h"
 #include "qlcconfig.h"
