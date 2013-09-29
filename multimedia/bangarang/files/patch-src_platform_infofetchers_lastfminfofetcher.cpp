--- src/platform/infofetchers/lastfminfofetcher.cpp.orig	2013-09-29 14:10:24.389000633 +0200
+++ src/platform/infofetchers/lastfminfofetcher.cpp	2013-09-29 14:12:08.529993792 +0200
@@ -32,6 +32,8 @@
 #include <QFile>
 #include <QTextEdit>
 
+#include <unistd.h>
+
 LastfmInfoFetcher::LastfmInfoFetcher(QObject *parent) :
         InfoFetcher(parent)
 {
