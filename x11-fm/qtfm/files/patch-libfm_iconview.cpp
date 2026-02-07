--- libfm/iconview.cpp.orig	2020-05-21 12:16:22 UTC
+++ libfm/iconview.cpp
@@ -1,4 +1,5 @@
 #include "iconview.h"
+#include <QPainterPath>
 
 bool IconViewDelegate::eventFilter(QObject *object,
                                    QEvent *event)
