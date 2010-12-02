--- ./src/plugins/dataforms/dataforms.cpp.orig	2010-02-04 23:15:54.000000000 +0300
+++ ./src/plugins/dataforms/dataforms.cpp	2010-12-02 00:40:53.396505897 +0300
@@ -1087,9 +1087,11 @@
     reply->ignoreSslErrors();
 }
 
+#if (QT_VERSION <= QT_VERSION_CHECK(4, 7, 0))
 uint qHash(const QUrl &key)
 {
   return qHash(key.toString());
 }
+#endif
 
 Q_EXPORT_PLUGIN2(plg_dataforms, DataForms);
