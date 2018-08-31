Fix build with Qt 5.11
Fixed upstream: https://github.com/keepassxreboot/keepassxc/commit/3bbc6ac

--- src/gui/entry/EditEntryWidget.cpp.orig	2018-08-31 04:04:41 UTC
+++ src/gui/entry/EditEntryWidget.cpp
@@ -29,6 +29,7 @@
 #include <QMenu>
 #include <QSortFilterProxyModel>
 #include <QTemporaryFile>
+#include <QButtonGroup>
 #include <QMimeData>
 #include <QEvent>
 #include <QColorDialog>
