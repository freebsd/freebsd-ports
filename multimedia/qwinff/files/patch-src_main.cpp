--- src/main.cpp.orig	2020-10-25 12:05:30 UTC
+++ src/main.cpp
@@ -30,6 +30,8 @@
 #include "services/notification.h"
 #include "services/constants.h"
 
+#define DATA_PATH "%%DATADIR%%"
+
 /**
  * @brief Find the absolute path of the translation of the current locale.
  *
