--- src/platform/infofetchers/tvdbinfofetcher.cpp.orig	2013-09-29 14:14:31.975991467 +0200
+++ src/platform/infofetchers/tvdbinfofetcher.cpp	2013-09-29 14:14:47.222983235 +0200
@@ -30,6 +30,8 @@
 #include <QDomDocument>
 #include <QFile>
 
+#include <unistd.h>
+
 TVDBInfoFetcher::TVDBInfoFetcher(QObject *parent) :
         InfoFetcher(parent)
 {
