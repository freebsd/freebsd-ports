--- ./src/tools/zip/zip.cpp.orig	2007-04-08 12:19:03.000000000 +0400
+++ ./src/tools/zip/zip.cpp	2008-07-30 01:52:00.000000000 +0400
@@ -23,7 +23,7 @@
 #include <QFile>
 
 #include "minizip/unzip.h"
-#include "zip.h"
+#include "psi-zip.h"
 
 class UnZipPrivate
 {
