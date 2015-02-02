--- src/lib/3rdparty/processinfo.h.orig	2014-09-26 12:35:35.000000000 +0400
+++ src/lib/3rdparty/processinfo.h	2014-09-26 23:04:10.000000000 +0400
@@ -18,16 +18,12 @@
 #ifndef PROCESSINFO_H
 #define PROCESSINFO_H
 
-#include <QtGlobal>
+#include "qzcommon.h"

 #if defined(Q_OS_UNIX) && !defined(Q_OS_MAC)
 #include <sys/types.h>
 #endif
 
-#include <QString>
-
-#include "qzcommon.h"
-
 /*
  * Code used from http://ubuntuforums.org/showpost.php?p=6593782&postcount=5
  * written by user WitchCraft 
