--- bakery/View/View_Composite.h.orig	Wed Aug 18 15:45:34 2004
+++ bakery/View/View_Composite.h	Wed Aug 18 15:45:52 2004
@@ -49,7 +49,7 @@
 	  //This should be unnecessary.
 	  if(pView)
 	  {
-  		pView->set_document(get_document());
+  		pView->set_document(type_view::get_document());
   		
   		//Add it to the list of child views:
   	  m_vecViews.push_back(pView);
