--- src/gdlwidget.hpp.orig	2017-05-19 17:32:58 UTC
+++ src/gdlwidget.hpp
@@ -275,7 +275,7 @@ protected:
   long  alignment; //alignment of the widget
   long widgetStyle; //style (alignment code + other specific codes used as option to widgetsizer) 
   int dynamicResize; //for some widgets, will enable resizing: -1: not resizable, 0/1 resizable
-  vector<WidgetIDT> followers; //all the widgets that use me as group_leader
+  std::vector<WidgetIDT> followers; //all the widgets that use me as group_leader
 
   
 private:  
@@ -1256,8 +1256,8 @@ public:
       if ( selectionCol.GetCount() > 0 ) return TRUE;
       return FALSE;
   }
-  vector<wxPoint> GetSelectedDisjointCellsList(){
-      vector<wxPoint> list;
+  std::vector<wxPoint> GetSelectedDisjointCellsList(){
+      std::vector<wxPoint> list;
       wxGridCellCoordsArray cellSelection=this->GetSelectedCells();
       for( int i=0; i<cellSelection.Count(); i++ ) {
        int row = cellSelection[i].GetRow();
