--- eiskaltdcpp-qt/src/HubFrame.cpp.orig	2013-08-29 21:25:02.000000000 +0400
+++ eiskaltdcpp-qt/src/HubFrame.cpp	2014-08-17 02:00:34.000000000 +0400
@@ -772,7 +772,7 @@
     }
 }
 
-HubFrame::HubFrame(QWidget *parent=NULL, QString hub="", QString encoding=""):
+HubFrame::HubFrame(QWidget *parent, QString hub, QString encoding):
         QWidget(parent),
         d_ptr(new HubFramePrivate())
 {
