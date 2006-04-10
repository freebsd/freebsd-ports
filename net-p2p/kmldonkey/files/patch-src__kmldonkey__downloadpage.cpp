--- ./src/kmldonkey/downloadpage.cpp.orig	Tue Jul 26 13:40:33 2005
+++ ./src/kmldonkey/downloadpage.cpp	Sun Apr  9 13:15:40 2006
@@ -68,6 +68,7 @@
     downloadView->addColumn( i18n( "Last seen" ) );
     downloadView->addColumn( i18n( "Age" ) );
     downloadView->addColumn( i18n( "File type" ) );
+    downloadView->addColumn( i18n( "Number" ) );
     downloadView->setItemsRenameable(true);
 
     downloadedView = new InfoList(downloadSplitter, "downloadedView", true);
