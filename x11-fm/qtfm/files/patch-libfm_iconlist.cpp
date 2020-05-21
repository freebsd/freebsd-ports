--- libfm/iconlist.cpp.orig	2020-05-21 12:16:22 UTC
+++ libfm/iconlist.cpp
@@ -1,4 +1,5 @@
 #include "iconlist.h"
+#include <QPainterPath>
 
 QSize IconListDelegate::sizeHint(const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const
