diff -u xgfeMainData.cpp.orig xgfeMainData.cpp
--- xgfeMainData.cpp.orig	Thu Oct 30 21:54:58 2003
+++ xgfeMainData.cpp	Thu Oct 30 21:42:04 2003
@@ -34,10 +34,13 @@
 #include <qpushbt.h>
 #include <qlayout.h>
 
+#define QColor(i)	(QColor)(i)
+#define QRgb(i)		(QRgb)(i)
+
 xgfeMainData::xgfeMainData
 (
- 	QWidget* parent = 0,
-	const char* name = 0
+ 	QWidget* parent,
+	const char* name
 )
 	:
   Inherited( parent, name, TRUE, WStyle_Customize | WStyle_NormalBorder 
