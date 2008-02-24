--- mainfrm.cpp	2008-02-08 19:27:04.000000000 +0100
+++ mainfrm.cpp.orig	2008-02-08 19:27:51.000000000 +0100
@@ -1367,9 +1367,9 @@
 				QString program = "cp";
 				QStringList arguments;
 				ispreview = 4;
-				arguments << "-r";
+				arguments << "-R";
 				arguments << "-f";
-				arguments << QApplication::applicationDirPath() + "/BIB_ManSlide/";
+				arguments << QApplication::applicationDirPath() + "/BIB_ManSlide";
 				arguments << path_library->text();
 				myprocess_9.start( program, arguments );
 			}
