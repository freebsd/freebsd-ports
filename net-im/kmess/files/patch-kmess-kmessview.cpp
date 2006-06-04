--- kmess/kmessview.cpp.orig	Sun Jun  4 15:13:33 2006
+++ kmess/kmessview.cpp	Sun Jun  4 15:14:27 2006
@@ -1058,7 +1058,7 @@
 {
   Contact *contact    = getContactByItem( contactListView_->currentItem() );
   Group   *oldGroup   = getGroupByItem( contactListView_->currentItem() );
-  QString  oldGroupId = (oldGroup != 0 ? oldGroup->getId() : "0");
+  QString  oldGroupId = (oldGroup != 0 ? oldGroup->getId() : QString::fromLatin1("0"));
 
   if(contact != 0)
   {
