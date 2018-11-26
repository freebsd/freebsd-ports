QHeaderView API change.

--- src/databasetool.cpp.orig	2018-11-26 11:45:00 UTC
+++ src/databasetool.cpp
@@ -65,7 +65,7 @@ DatabaseTool::DatabaseTool(QWidget* pare
 
     grainpage.view->verticalHeader()->setDefaultSectionSize(mh);
     grainpage.view->verticalHeader()->hide();
-    grainpage.view->horizontalHeader()->setClickable(true);
+    grainpage.view->horizontalHeader()->setSectionsClickable(true);
     grainpage.view->horizontalHeader()->setHighlightSections(false);
 
     grainpage.view->setColumnWidth(GrainModel::NAME, 20*mw);
@@ -88,7 +88,7 @@ DatabaseTool::DatabaseTool(QWidget* pare
 
     hoppage.view->verticalHeader()->setDefaultSectionSize(mh);
     hoppage.view->verticalHeader()->hide();
-    hoppage.view->horizontalHeader()->setClickable(true);
+    hoppage.view->horizontalHeader()->setSectionsClickable(true);
     hoppage.view->horizontalHeader()->setHighlightSections(false);
 
     hoppage.view->setColumnHidden(HopModel::WEIGHT, true);
@@ -110,7 +110,7 @@ DatabaseTool::DatabaseTool(QWidget* pare
 
     miscpage.view->verticalHeader()->setDefaultSectionSize(mh);
     miscpage.view->verticalHeader()->hide();
-    miscpage.view->horizontalHeader()->setClickable(true);
+    miscpage.view->horizontalHeader()->setSectionsClickable(true);
     miscpage.view->horizontalHeader()->setHighlightSections(false);
 
     miscpage.view->setColumnHidden(MiscModel::QUANTITY, true);
@@ -131,7 +131,7 @@ DatabaseTool::DatabaseTool(QWidget* pare
 
     stylepage.view->verticalHeader()->setDefaultSectionSize(mh);
     stylepage.view->verticalHeader()->hide();
-    stylepage.view->horizontalHeader()->setClickable(true);
+    stylepage.view->horizontalHeader()->setSectionsClickable(true);
     stylepage.view->horizontalHeader()->setHighlightSections(false);
 
     stylepage.view->setColumnWidth(StyleModel::NAME, 20*mw);
