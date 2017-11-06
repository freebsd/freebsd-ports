--- widgets/MW_help.cpp.orig	2015-10-10 12:54:12 UTC
+++ widgets/MW_help.cpp
@@ -67,8 +67,8 @@ void MainWindow::about()
 	{
 		version = QString("<table border=0 width=500><tr>"
 				"<td>Compile time:</td>"
-				"<td>"OPENSSL_VERSION_TEXT"</td>"
-				"<td>QT version: "QT_VERSION_STR"</td>"
+				"<td>" OPENSSL_VERSION_TEXT "</td>"
+				"<td>QT version: " QT_VERSION_STR "</td>"
 				"</tr><tr>"
 				"<td>Run time:</td>"
 				"<td>%1</td>"
