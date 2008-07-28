--- mainfrm.cpp	2008-07-06 23:36:59.000000000 +0200
+++ mainfrm.cpp.new	2008-07-06 23:38:27.000000000 +0200
@@ -815,9 +815,9 @@
 			QString program = "cp";
 			QStringList arguments;
 			ispreview = 4;
-			arguments << "-r";
+			arguments << "-R";
 			arguments << "-f";
-			arguments << QApplication::applicationDirPath() + "/BIB_ManSlide/";
+			arguments << QApplication::applicationDirPath() + "/BIB_ManSlide";
 			arguments << tempfolder->text();
 			myprocess_9.start( program, arguments );
 			//
