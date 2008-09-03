--- ../ark/plugins/libzipplugin/zipplugin.cpp.orig	2008-08-30 13:07:45.000000000 +0400
+++ ../ark/plugins/libzipplugin/zipplugin.cpp	2008-08-30 13:12:59.000000000 +0400
@@ -30,8 +30,8 @@
 //usually compiled with off_t to 32bit. in the long run libzip should be
 //compiled according to bugs.kde.org bug #167018
 //but for now this will probably do
-#define __off_t_defined
-typedef quint32 off_t;
+// #define __off_t_defined
+// typedef quint32 off_t;
 
 #include "kerfuffle/archiveinterface.h"
 #include "kerfuffle/archivefactory.h"
