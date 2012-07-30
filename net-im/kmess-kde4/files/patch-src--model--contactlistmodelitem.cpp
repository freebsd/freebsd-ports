--- src/model/contactlistmodelitem.cpp.orig	2012-07-03 01:35:16.000000000 -0500
+++ src/model/contactlistmodelitem.cpp	2012-07-03 01:35:50.000000000 -0500
@@ -79,7 +79,8 @@
  */
 ContactListModelItem::~ContactListModelItem()
 {
-  qDeleteAll( childItems_ );
+  while( !childItems_.isEmpty() )
+    delete childItems_.takeFirst();
   childItems_.clear();
 
   // Delete this item from the parent's children
