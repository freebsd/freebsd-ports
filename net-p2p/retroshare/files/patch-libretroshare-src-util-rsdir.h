--- libretroshare/src/util/rsdir.h.orig	2011-05-15 14:42:55.000000000 +0200
+++ libretroshare/src/util/rsdir.h	2012-01-15 20:10:19.000000000 +0100
@@ -31,6 +31,17 @@
 #include <string>
 #include <list>
 #include <stdint.h>
+#include <fnmatch.h>
+
+#include <dirent.h>
+#include <unistd.h>
+#define O_LARGEFILE      0100000
+#define stat64 stat
+#define _stat stat
+#define _getcwd getcwd
+#define fseeko64 fseeko
+#define fopen64 fopen
+#define ftello64 ftello
 
 class CRC32Map ;
 class RsThread;
