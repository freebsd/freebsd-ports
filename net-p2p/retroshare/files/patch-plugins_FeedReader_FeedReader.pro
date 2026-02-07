--- plugins/FeedReader/FeedReader.pro.orig	2016-02-05 19:04:46 UTC
+++ plugins/FeedReader/FeedReader.pro
@@ -134,3 +134,8 @@ haiku-* {
 
 	LIBS += -lcurl -lxml2 -lxslt
 }
+
+freebsd-* {
+	INCLUDEPATH += $$system(pkg-config --cflags libxml-2.0 | sed -e "s/-I//g")
+	LIBS += -lcurl -lxml2 -lxslt
+}
