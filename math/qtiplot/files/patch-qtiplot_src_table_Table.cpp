Description: if you don't initialize the "i" variable, or initialize it to 0.0
 qtiplot won't let you set the column values using muparser.
Author: Scott Howard <showard@debian.org>
Bug-Debian: http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=707736

Index: qtiplot/qtiplot/src/table/Table.cpp
===================================================================
--- qtiplot/src/table/Table.cpp.orig	2011-09-13 11:20:29 UTC
+++ qtiplot/src/table/Table.cpp
@@ -564,7 +564,7 @@ bool Table::muParserCalculate(int col, i
 	QApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
 
     muParserScript *mup = new muParserScript(scriptEnv, cmd, this,  QString("<%1>").arg(colName(col)));
-    double *r = mup->defineVariable("i");
+    double *r = mup->defineVariable("i",startRow + 1.0);
     mup->defineVariable("j", (double)col);
     mup->defineVariable("sr", startRow + 1.0);
     mup->defineVariable("er", endRow + 1.0);
