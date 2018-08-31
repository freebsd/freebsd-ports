Fix build with Qt 5.11
Obtained from: https://sourceforge.net/p/qmmp-dev/code/7986/

--- src/qmmpui/detailsdialog.cpp.orig	2018-08-31 05:09:00 UTC
+++ src/qmmpui/detailsdialog.cpp
@@ -24,6 +24,7 @@
 #include <QFileInfo>
 #include <QProcess>
 #include <QPushButton>
+#include <QStyle>
 #include <qmmp/metadatamanager.h>
 #include <qmmp/metadatamodel.h>
 #include <qmmp/tagmodel.h>
