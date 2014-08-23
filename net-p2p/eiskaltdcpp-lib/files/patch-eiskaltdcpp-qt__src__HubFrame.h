--- eiskaltdcpp-qt/src/HubFrame.h.orig	2014-08-17 01:57:00.000000000 +0400
+++ eiskaltdcpp-qt/src/HubFrame.h	2014-08-17 01:57:33.000000000 +0400
@@ -128,7 +128,7 @@
     typedef QMap<QString, QVariant> VarMap;
     typedef QList<ShellCommandRunner*> ShellList;
 
-    HubFrame(QWidget *parent, QString, QString);
+    HubFrame(QWidget *parent=NULL, QString hub="", QString encoding="");
     ~HubFrame();
 
     bool parseForCmd(QString, QWidget *);
