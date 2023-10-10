--- widget/gtk/nsMenuBar.cpp.orig	2023-10-06 21:47:06.056933000 +0200
+++ widget/gtk/nsMenuBar.cpp	2023-10-06 21:44:31.623574000 +0200
@@ -190,7 +190,7 @@
 
     mEventListener = new DocEventListener(this);
 
-    mDocument = do_QueryInterface(ContentNode()->OwnerDoc());
+    mDocument = ContentNode()->OwnerDoc();
 
     mAccessKey = Preferences::GetInt("ui.key.menuAccessKey");
     if (mAccessKey == dom::KeyboardEvent_Binding::DOM_VK_SHIFT) {
