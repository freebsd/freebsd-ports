--- kadu-core/main.cpp.orig	2009-01-04 14:18:33.000000000 +0100
+++ kadu-core/main.cpp	2009-03-07 18:12:29.000000000 +0100
@@ -19,7 +19,7 @@
 #else
 #include <winsock2.h>
 #endif
-#ifdef Q_WS_MAC
+#ifdef Q_OS_BSD4
 #include <sys/types.h>
 #include <sys/stat.h>
 #endif
