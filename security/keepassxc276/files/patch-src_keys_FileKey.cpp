--- src/keys/FileKey.cpp.orig	2023-08-15 22:40:34 UTC
+++ src/keys/FileKey.cpp
@@ -22,6 +22,8 @@
 #include "crypto/CryptoHash.h"
 #include "crypto/Random.h"
 
+#include <botan/mem_ops.h>
+
 #include <QDataStream>
 #include <QFile>
 #include <QXmlStreamReader>
