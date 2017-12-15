--- src/MuleNotebook.cpp.orig	2017-06-03 23:55:41.000000000 +0200
+++ src/MuleNotebook.cpp	2017-11-20 14:51:19.834947000 +0100
@@ -45,10 +45,10 @@
 	EVT_MENU(MP_CLOSE_OTHER_TABS,	CMuleNotebook::OnPopupCloseOthers)
 
 	// Madcat - tab closing engine
-	EVT_LEFT_DOWN(CMuleNotebook::OnMouseButtonRelease)
-	EVT_LEFT_UP(CMuleNotebook::OnMouseButtonRelease)
-	EVT_MIDDLE_DOWN(CMuleNotebook::OnMouseButtonRelease)
-	EVT_MIDDLE_UP(CMuleNotebook::OnMouseButtonRelease)
+	EVT_LEFT_DOWN(CMuleNotebook::OnMouseButton)
+	EVT_LEFT_UP(CMuleNotebook::OnMouseButton)
+	EVT_MIDDLE_DOWN(CMuleNotebook::OnMouseButton)
+	EVT_MIDDLE_UP(CMuleNotebook::OnMouseButton)
 	EVT_MOTION(CMuleNotebook::OnMouseMotion)
 #if MULE_NEEDS_DELETEPAGE_WORKAROUND
 	EVT_MULENOTEBOOK_DELETE_PAGE(wxID_ANY, CMuleNotebook::OnDeletePage)
@@ -217,7 +217,7 @@
 }
 
 
-void CMuleNotebook::OnMouseButtonRelease(wxMouseEvent &event)
+void CMuleNotebook::OnMouseButton(wxMouseEvent &event)
 {
 	if (GetImageList() == NULL) {
 		// This Mulenotebook has no images on tabs, so nothing to do.
@@ -235,16 +235,13 @@
 
 	if (event.LeftDown() &&  (flags == wxNB_HITTEST_ONICON)) {
 		tab_down_icon = tab;
-		return;
 	}
 	else if (event.MiddleDown() && (flags == wxNB_HITTEST_ONLABEL)) {
 		tab_down_label = tab;
-		return;
 	}
 	else if (event.LeftDown() || event.MiddleDown()) {
 		tab_down_icon = -1;
 		tab_down_label = -1;
-		return;
 	}
 	
 	if (((tab != -1) &&  (((flags == wxNB_HITTEST_ONICON) && event.LeftUp() && (tab == tab_down_icon)) ||
