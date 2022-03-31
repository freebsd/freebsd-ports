--- src/keeshare/ShareExport.cpp.orig	2022-03-21 22:47:20 UTC
+++ src/keeshare/ShareExport.cpp
@@ -27,7 +27,7 @@
 
 #include <QBuffer>
 #include <botan/pubkey.h>
-#include <zip.h>
+#include <minizip/zip.h>
 
 namespace
 {
