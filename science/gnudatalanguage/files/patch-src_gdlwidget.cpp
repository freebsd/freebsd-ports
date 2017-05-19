--- src/gdlwidget.cpp.orig	2017-05-19 17:32:58 UTC
+++ src/gdlwidget.cpp
@@ -2455,7 +2455,7 @@ BaseGDL* GDLWidgetTable::GetTableValuesA
   } 
   else { //use the wxWidget selection or the passed selection, mode-dependent:
     if (disjointSelection) { //pairs lists
-      vector<wxPoint> list;
+      std::vector<wxPoint> list;
       if (selection->Rank()==0) { //use current wxWidgets selection. Result is a STRUCT
         list=grid->GetSelectedDisjointCellsList();
       } else {                   //make equivalent vector.
