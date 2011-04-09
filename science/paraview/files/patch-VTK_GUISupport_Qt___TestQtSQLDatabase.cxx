--- VTK/GUISupport/Qt/Testing/Cxx/TestQtSQLDatabase.cxx.orig	2011-04-01 14:22:01.000000000 +0700
+++ VTK/GUISupport/Qt/Testing/Cxx/TestQtSQLDatabase.cxx	2011-04-01 14:23:32.000000000 +0700
@@ -21,7 +21,7 @@
 
 // Check for Qt SQL module before defining this test.
 #include <qglobal.h>
-#if (QT_EDITION & QT_MODULE_SQL)
+#if (defined(QT_EDITION) & defined(QT_MODULE_SQL))
 #include "vtkQtSQLDatabase.h"
 #include "vtkSQLQuery.h"
 #include "vtkRowQueryToTable.h"
