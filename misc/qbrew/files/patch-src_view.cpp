QHeaderView API change

--- src/view.cpp.orig	2018-11-26 11:59:12 UTC
+++ src/view.cpp
@@ -72,7 +72,7 @@ View::View(QWidget *parent, Recipe *reci
 
     grainpage.view->verticalHeader()->setDefaultSectionSize(mh);
     grainpage.view->verticalHeader()->hide();
-    grainpage.view->horizontalHeader()->setClickable(true);
+    grainpage.view->horizontalHeader()->setSectionsClickable(true);
     grainpage.view->horizontalHeader()->setHighlightSections(false);
 
     grainpage.view->setColumnWidth(GrainModel::NAME, 20*mw);
@@ -94,7 +94,7 @@ View::View(QWidget *parent, Recipe *reci
 
     hoppage.view->verticalHeader()->setDefaultSectionSize(mh);
     hoppage.view->verticalHeader()->hide();
-    hoppage.view->horizontalHeader()->setClickable(true);
+    hoppage.view->horizontalHeader()->setSectionsClickable(true);
     hoppage.view->horizontalHeader()->setHighlightSections(false);
 
     hoppage.view->setColumnWidth(HopModel::NAME, 20*mw);
@@ -115,7 +115,7 @@ View::View(QWidget *parent, Recipe *reci
 
     miscpage.view->verticalHeader()->setDefaultSectionSize(mh);
     miscpage.view->verticalHeader()->hide();
-    miscpage.view->horizontalHeader()->setClickable(true);
+    miscpage.view->horizontalHeader()->setSectionsClickable(true);
     miscpage.view->horizontalHeader()->setHighlightSections(false);
 
     miscpage.view->setColumnWidth(MiscModel::NAME, 20*mw);
