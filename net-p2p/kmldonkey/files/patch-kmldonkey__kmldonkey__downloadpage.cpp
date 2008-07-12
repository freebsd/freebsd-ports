--- ./kmldonkey/kmldonkey/downloadpage.cpp.orig	2008-06-19 20:56:42.000000000 -0300
+++ ./kmldonkey/kmldonkey/downloadpage.cpp	2008-07-12 06:02:12.000000000 -0300
@@ -88,6 +88,7 @@
     downloadView->addColumn( i18n( "Last seen" ) );
     downloadView->addColumn( i18n( "Age" ) );
     downloadView->addColumn( i18n( "File type" ) );
+    downloadView->addColumn( i18n( "Number" ) );
     downloadView->setItemsRenameable( true );
 
     downloadedView = new InfoList( downloadSplitter, "downloadedView", true );
