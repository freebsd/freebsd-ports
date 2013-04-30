--- uibase.cpp.orig
+++ uibase.cpp
@@ -139,7 +139,7 @@
 
     m_WalletSelect = new wxComboBox(this, wxID_ANY, wxEmptyString,wxDefaultPosition,wxDefaultSize,0,0,wxCB_READONLY);
     m_WalletSelect->SetToolTip(wxT("Change your wallet to view other transactions and address books"));
-    wxFont font2(15, wxFONTFAMILY_TELETYPE, wxNORMAL, wxBOLD);
+    wxFont font2(15, wxFONTFAMILY_TELETYPE, wxNORMAL, wxBOLD, false, wxEmptyString, wxFONTENCODING_DEFAULT);
     m_WalletSelect->SetFont(font2);
 
 
@@ -162,7 +162,7 @@
 	wxBoxSizer* bSizer66;
 	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
 
-    wxFont font3(12, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL);
+    wxFont font3(12, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL, false, wxEmptyString, wxFONTENCODING_DEFAULT);
     m_toolBar = new wxToolBar(this, wxID_ANY ,wxDefaultPosition,wxDefaultSize,wxTB_TEXT|wxTB_HORZ_LAYOUT |wxTB_FLAT );
 
 	m_toolBar->SetToolBitmapSize( wxSize( 20,20 ) );
