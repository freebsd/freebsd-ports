--- mainfrm.cpp	2008-08-04 10:44:08.000000000 +0200
+++ mainfrm.cpp.new	2008-08-04 12:02:17.000000000 +0200
@@ -1284,9 +1284,9 @@
 				arguments << tempfolder->text();
 			#else
 				program = "cp";
-				arguments << "-r";
+				arguments << "-R";
 				arguments << "-f";
-				arguments << QApplication::applicationDirPath() + "/BIB_ManSlide/";
+				arguments << QApplication::applicationDirPath() + "/BIB_ManSlide";
 				arguments << tempfolder->text();
 			#endif
 			ispreview = 4;
