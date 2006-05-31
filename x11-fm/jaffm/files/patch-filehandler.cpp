--- filehandler.cpp.orig	Sat Sep 17 17:28:48 2005
+++ filehandler.cpp	Sun May 21 20:00:02 2006
@@ -1,5 +1,11 @@
 #include "filehandler.h"
+#include <stdio.h>
+#include <unistd.h>
 #include <sys/stat.h>
+
+#ifndef X_OK
+#define X_OK  0x01
+#endif
 
 bool UFileHandler::move(const std::string &sOriginal, const std::string &sDestination)
 {
