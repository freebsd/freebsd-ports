--- scribus/helpbrowser.cpp.orig	Fri Jan  7 05:18:30 2005
+++ scribus/helpbrowser.cpp	Mon Jan 10 22:11:45 2005
@@ -58,7 +58,7 @@
 	QString fileName;
 	mHistory.clear();
 	struct histd his;
-	language = guiLanguage=="" ? "en" : guiLanguage.left(2);
+	language = guiLanguage=="" ? QString( "en" ) : guiLanguage.left(2);
 	helpBrowsermainLayout = new QVBoxLayout( this); 
 	buttonLayout = new QHBoxLayout;
 	buttonLayout->setSpacing( 6 );
