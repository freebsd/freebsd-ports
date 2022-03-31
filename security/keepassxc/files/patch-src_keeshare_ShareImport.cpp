--- src/keeshare/ShareImport.cpp.orig	2022-03-21 22:47:20 UTC
+++ src/keeshare/ShareImport.cpp
@@ -21,7 +21,7 @@
 #include "keys/PasswordKey.h"
 
 #include <QBuffer>
-#include <unzip.h>
+#include <minizip/unzip.h>
 
 namespace
 {
