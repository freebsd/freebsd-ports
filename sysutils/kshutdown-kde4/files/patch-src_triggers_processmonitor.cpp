--- src/triggers/processmonitor.cpp.orig	2018-03-09 21:45:20 UTC
+++ src/triggers/processmonitor.cpp
@@ -20,6 +20,7 @@
 #include "../config.h"
 #include "../utils.h"
 
+#include <errno.h>
 #include <QHBoxLayout>
 #include <QPushButton>
 
