--- src/modules/qt/filter_qtext.cpp.orig	2020-03-22 06:37:39 UTC
+++ src/modules/qt/filter_qtext.cpp
@@ -21,6 +21,7 @@
 #include <framework/mlt.h>
 #include <framework/mlt_log.h>
 #include <QPainter>
+#include <QPainterPath>
 #include <QString>
 
 static QRectF get_text_path( QPainterPath* qpath, mlt_properties filter_properties, const char* text, double scale )
