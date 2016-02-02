--- src/lib/random.cpp.orig	2009-06-28 14:22:31 UTC
+++ src/lib/random.cpp
@@ -29,6 +29,7 @@
 	#include <QSysInfo>
 #endif
 
+#include <unistd.h>
 #include <QCryptographicHash>
 #include <QCursor>
 #include <QDataStream>
