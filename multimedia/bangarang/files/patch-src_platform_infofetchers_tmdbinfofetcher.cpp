--- src/platform/infofetchers/tmdbinfofetcher.cpp.orig	2013-09-29 14:13:28.088988439 +0200
+++ src/platform/infofetchers/tmdbinfofetcher.cpp	2013-09-29 14:13:39.271987399 +0200
@@ -30,6 +30,8 @@
 #include <QDomDocument>
 #include <QFile>
 
+#include <unistd.h>
+
 TMDBInfoFetcher::TMDBInfoFetcher(QObject *parent) :
         InfoFetcher(parent)
 {
