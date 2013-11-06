--- plugins/FeedReader/FeedReader.pro.orig	2013-10-22 11:53:29.000000000 +0200
+++ plugins/FeedReader/FeedReader.pro	2013-10-22 11:54:10.000000000 +0200
@@ -101,3 +101,9 @@
 	LIBS += -lcurl -lxml2 -lxslt
 }
 
+freebsd-* {
+
+	INCLUDEPATH += /usr/local/include/libxml2
+
+	LIBS += -lcurl -lxml2 -lxslt
+}
