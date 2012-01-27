--- libretroshare/src/dbase/findex.h.orig	2011-04-15 22:21:52.000000000 +0200
+++ libretroshare/src/dbase/findex.h	2012-01-15 03:55:27.000000000 +0100
@@ -33,6 +33,14 @@
 #include <stdint.h>
 #include "retroshare/rstypes.h"
 
+#include <dirent.h>
+#include <fnmatch.h>
+#include <unistd.h>
+#define O_LARGEFILE      0100000
+#define stat64 stat
+#define _stat stat
+#define _getcwd getcwd
+
 class ostream;
 
 /******************************************************************************************
