--- kst/kst/kst.cpp.orig	Sun Apr 30 00:32:11 2006
+++ kst/kst/kst.cpp	Sun Apr 30 00:40:06 2006
@@ -1489,7 +1489,7 @@
   bool firstPage = true;
   while (it->currentItem()) {
     KstViewWindow *win = dynamic_cast<KstViewWindow*>(it->currentItem());
-    KstTopLevelViewPtr tlv = win ? kst_cast<KstTopLevelView>(win->view()) : 0L;
+    KstTopLevelViewPtr tlv = win ? kst_cast<KstTopLevelView>(win->view()) : static_cast<KstTopLevelViewPtr>(0L);
     if (win && tlv && !tlv->children().isEmpty()) {
       ++pages;
 #if KDE_VERSION < KDE_MAKE_VERSION(3,3,0)
